#pragma once

/**
 * \brief Фигуры игроков в игре крестики-нолики
 */
enum class figure_enum
{
	// крестик
	cross,

	// нолик
	nought,

	// пустая клетка
	empty
};

class figure
{
private:
	/**
	 * \brief Хранимая в клетке фигура
	 */
	figure_enum figure_;

public:
	figure() : figure_(figure_enum::empty) {}

	explicit figure(const figure_enum& figure_enum) : figure_(figure_enum) {}

	/**
	 * \brief Метод для получения фигуры
	 * \return Значение фигуры
	 */
	[[nodiscard]] figure_enum get() const;

	/**
	 * \brief Установка фигуры
	 * \param figure Значение, которое нужно установить
	 */
	void set(const figure_enum& figure);

	/**
	 * \brief Функция для сравнения двух фигур по значению
	 * \param left левая от двойного равно фигура
	 * \param right правая от двойного равно фигура
	 * \return результат сравнения
	 */
	friend bool operator== (const figure& left, const figure& right);

	/**
	 * \brief Метод для получения численного значения фигуры
	 * \return Порядковый номер фигуры
	 */
	[[nodiscard]] int get_int() const;

	/**
	 * \brief Метод для получения символьного представления фигуры
	 * \return Символ данной фигуры
	 */
	[[nodiscard]] char get_char() const;

	/**
	 * \brief Метод для определения того, является ли данная фигура пустой
	 * \return Состояние пустоты фигуры
	 */
	[[nodiscard]] bool is_empty() const;

	/**
	 * \brief Метод возвращающий новую фигуру, противоположную данной
	 * Если вызывается для пустой, то возвращает новую с пустым значением
	 * \return Новая фигура с противоположным значением
	 */
	[[nodiscard]] figure get_opposite_figure() const;

	/**
	 * \brief Статический метод для получения фигуры с пустым значением
	 * \return Фигура с пустым значением
	 */
	static figure get_empty_figure();
};