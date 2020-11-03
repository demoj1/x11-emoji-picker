#pragma once

#include "EmojiLabel.hpp"
#include "EmojiLineEdit.hpp"
#include "emojis.hpp"
#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <vector>

class EmojiPicker : public QWidget {
  Q_OBJECT

public:
  explicit EmojiPicker(QWidget* parent = nullptr);

signals:
  void returnPressed(const std::string& emojiStr);
  void escapePressed();

protected:
  void wheelEvent(QWheelEvent* event) override;

private:
  static const int cols = 10;
  static const int rows = 4;

  std::vector<Emoji> _recentEmojis;
  bool _skinTonesDisabled = false;
  bool _gendersDisabled = false;

  EmojiLabel* _selectedEmojiLabel = nullptr;

  QVBoxLayout* _mainLayout = new QVBoxLayout();

  QWidget* _emojiLayoutWidget = new QWidget();
  QGridLayout* _emojiLayout = new QGridLayout();

  EmojiLineEdit* _emojiEdit = new EmojiLineEdit();

  int _helpEmojiListIdx = -1;
  int _helpEmojiListDir = +1;
  Emoji _helpEmojiListStartEmoji = {"", ""};

  void setSelectedEmojiLabel(EmojiLabel* emojiLabel);

  bool addEmojiLabel(EmojiLabel* emojiLabel, int& row, int& col);

  bool isDisabledEmoji(const Emoji& emoji);

  void clearView();
  void fillViewWithRecentEmojis();
  void fillViewWithEmojisByText(const std::string& text);
  void fillViewWithEmojisByList();

private slots:
  void onTextChanged(const QString& text);
  void onReturnPressed();
  void onArrowKeyPressed(int key);
  void onEscapePressed();
  void onFunctionKeyPressed(int key);

  void onHelpPressed(QMouseEvent* ev);
};
