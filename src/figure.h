#pragma once

/**
 * \brief ������ ������� � ���� ��������-������
 */
enum class figure_enum
{
	// �������
	cross,

	// �����
	nought,

	// ������ ������
	empty
};

class figure
{
private:
	/**
	 * \brief �������� � ������ ������
	 */
	figure_enum figure_;

public:
	figure() : figure_(figure_enum::empty) {}

	explicit figure(const figure_enum& figure_enum) : figure_(figure_enum) {}

	/**
	 * \brief ����� ��� ��������� ������
	 * \return �������� ������
	 */
	[[nodiscard]] figure_enum get() const;

	/**
	 * \brief ��������� ������
	 * \param figure ��������, ������� ����� ����������
	 */
	void set(const figure_enum& figure);

	/**
	 * \brief ������� ��� ��������� ���� ����� �� ��������
	 * \param left ����� �� �������� ����� ������
	 * \param right ������ �� �������� ����� ������
	 * \return ��������� ���������
	 */
	friend bool operator== (const figure& left, const figure& right);

	/**
	 * \brief ����� ��� ��������� ���������� �������� ������
	 * \return ���������� ����� ������
	 */
	[[nodiscard]] int get_int() const;

	/**
	 * \brief ����� ��� ��������� ����������� ������������� ������
	 * \return ������ ������ ������
	 */
	[[nodiscard]] char get_char() const;

	/**
	 * \brief ����� ��� ����������� ����, �������� �� ������ ������ ������
	 * \return ��������� ������� ������
	 */
	[[nodiscard]] bool is_empty() const;

	/**
	 * \brief ����� ������������ ����� ������, ��������������� ������
	 * ���� ���������� ��� ������, �� ���������� ����� � ������ ���������
	 * \return ����� ������ � ��������������� ���������
	 */
	[[nodiscard]] figure get_opposite_figure() const;

	/**
	 * \brief ����������� ����� ��� ��������� ������ � ������ ���������
	 * \return ������ � ������ ���������
	 */
	static figure get_empty_figure();
};