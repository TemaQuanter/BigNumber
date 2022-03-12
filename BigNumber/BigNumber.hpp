#include <iostream>
#include <algorithm>

using namespace std;

class BigNumber
{
	private:
		string value = "0";


		string get_sum(string s1, string s2)
		{
			if (is_negative(s1) && is_negative(s2))
			{
				return "-" + get_sum(get_abs(s1), get_abs(s2));
			}
			if (is_negative(s1) && !is_negative(s2))
			{
				return get_difference(s2, get_abs(s1));
			}
			if (!is_negative(s1) && is_negative(s2))
			{
				return get_difference(s1, get_abs(s2));
			}

			string reply = "";

			if (s1.size() < s2.size())
			{
				swap(s1, s2);
			}

			reverse(s1.begin(), s1.end());
			reverse(s2.begin(), s2.end());
			
			s1 += "0";

			while (s2.size() < s1.size())
			{
				s2 += "0";
			}

			bool reminder = false;

			for (int i = 0; i < s1.size(); i++)
			{
				if (reminder)
				{
					short small_number = (s1[i] - '0') + (s2[i] - '0') + 1;
					reply += ('0' + small_number % 10);
					if (small_number >= 10)
					{
						reminder = true;
					}
					else
					{
						reminder = false;
					}
				}
				else
				{	
					short small_number = (s1[i] - '0') + (s2[i] - '0');
					reply += ('0' + small_number % 10);
					if (small_number >= 10)
					{
						reminder = true;
					}
					else
					{
						reminder = false;
					}
				}
			}

			while (reply.back() == '0')
			{
				reply.pop_back();
			}

			reverse(reply.begin(), reply.end());

			return reply;
		}


		string get_difference(string s1, string s2)
		{
			if (is_equal(s1, s2))
			{
				return "0";
			}
			if (is_negative(s1) && !is_negative(s2))
			{
				return "-" + get_sum(get_abs(s1), s2);
			}
			if (!is_negative(s1) && is_negative(s2))
			{
				return get_sum(s1, get_abs(s2));
			}

			bool result_is_negative = false;

			if (is_negative(s1) && is_negative(s2) && is_less(get_abs(s1), get_abs(s2)))
			{
				result_is_negative = false;
			}
			else if (!is_negative(s1) && !is_negative(s2) && is_less(get_abs(s1), get_abs(s2)))
			{
				result_is_negative = true;
			}
			else if (is_negative(s1) && is_negative(s2) && is_greater(get_abs(s1), get_abs(s2)))
			{
				result_is_negative = true;
			}
			else if (!is_negative(s1) && !is_negative(s2) && is_greater(get_abs(s1), get_abs(s2)))
			{
				result_is_negative = false;
			}

			s1 = get_abs(s1);
			s2 = get_abs(s2);

			if (is_less(s1, s2))
			{
				swap(s1, s2);
			}

			reverse(s1.begin(), s1.end());
			reverse(s2.begin(), s2.end());

			while (s2.size() < s1.size())
			{
				s2 += "0";
			}

			string reply = "";

			bool reminder = false;

			for (int i = 0; i < s1.size(); i++)
			{
				if (reminder)
				{
					int small_number = ((s1[i] - '0') - 1) - (s2[i] - '0');
					if (small_number < 0)
					{
						small_number += 10;
						reminder = true;
					}
					else
					{
						reminder = false;
					}
					reply += ('0' + small_number);
				}
				else
				{
					int small_number = (s1[i] - '0') - (s2[i] - '0');
					if (small_number < 0)
					{
						small_number += 10;
						reminder = true;
					}
					else
					{
						reminder = false;
					}
					reply += ('0' + small_number);
				}
			}

			while (reply.back() == '0')
			{
				reply.pop_back();
			}

			reverse(reply.begin(), reply.end());

			if (result_is_negative)
			{
				return "-" + reply;
			}

			return reply;
		}


		string get_product(string s1, string s2)
		{
			if (is_equal(s1, "0") || is_equal(s2, "0"))
			{
				return "0";
			}

			bool result_is_negative = false;

			if (is_negative(s1) && is_negative(s2))
			{
				result_is_negative = false;
			}
			else if (is_negative(s1) && !is_negative(s2))
			{
				result_is_negative = true;
			}
			else if (!is_negative(s1) && is_negative(s2))
			{
				result_is_negative = true;
			}
			else if (!is_negative(s1) && !is_negative(s2))
			{
				result_is_negative = false;
			}

			s1 = get_abs(s1);
			s2 = get_abs(s2);

			if (is_less(s1, s2))
			{
				swap(s1, s2);
			}

			string reply = "0";
			string cur_reply = "";
			short reminder = 0;

			for (int i = s2.size() - 1; i > -1; i--)
			{
				cur_reply = "";
				reminder = 0;
				
				for (int j = s1.size() - 1; j > -1; j--)
				{
					short small_number = (s2[i] - '0') * (s1[j] - '0') + reminder;
					
					reminder = small_number / 10;
					cur_reply += ('0' + (small_number % 10));
				}
				
				if (reminder > 0)
				{
					cur_reply += ('0' + reminder);
				}
				
				reverse(cur_reply.begin(), cur_reply.end());
				
				for (int j = 0; j < (s2.size() - 1 - i); j++)
				{
					cur_reply += "0";
				}

				reply = get_sum(reply, cur_reply);
			}

			if (result_is_negative)
			{
				return "-" + reply;
			}

			return reply;
		}


		string get_quotient(string s1, string s2)
		{
			if (is_equal(s2, "0"))
			{
				return "0";
			}

			if (is_less(get_abs(s1), get_abs(s2)))
			{
				return "0";
			}

			bool result_is_negative = false;

			if (is_negative(s1) && is_negative(s2))
			{
				result_is_negative = false;
			}
			else if (is_negative(s1) && !is_negative(s2))
			{
				result_is_negative = true;
			}
			else if (!is_negative(s1) && is_negative(s2))
			{
				result_is_negative = true;
			}
			else if (!is_negative(s1) && !is_negative(s2))
			{
				result_is_negative = false;
			}

			s1 = get_abs(s1);
			s2 = get_abs(s2);

			string reply = "";
			string seg = "";

			int ind = 0;

			for (; ind < s2.size(); ind++)
			{
				seg += s1[ind];
			}

			if (is_less(seg, s2))
			{
				seg += s1[ind];
				ind++;
			}

			string cur_reply = "0";

			while (ind <= s1.size())
			{
				cur_reply = "0";
				for (short i = 1; i <= 10; i++)
				{
					cur_reply = get_sum(cur_reply, s2);
					if (is_greater(cur_reply, seg))
					{
						cur_reply = get_difference(cur_reply, s2);
						reply += ('0' + (i - 1));
						break;
					}
				}
				seg = get_difference(seg, cur_reply);
				
				if (seg == "0")
				{
					seg = "";
				}

				if (ind == s1.size())
				{
					break;
				}
				seg += s1[ind];
				ind++;
			}

			if (result_is_negative)
			{
				return "-" + get_sum(reply, "1");
			}

			return reply;
		}


		string get_reminder(string s1, string s2)
		{
			return get_difference(s1, get_product(s2, get_quotient(s1, s2)));
		}


		bool is_negative(string s)
		{
			if (s.front() == '-')
			{
				return true;
			}
			return false;
		}


		string get_abs(string s)
		{
			if (is_negative(s))
			{
				s.erase(s.begin());
			}
			return s;
		}
		

		bool is_greater(string s1, string s2)
		{
			if (!is_negative(s1) && is_negative(s2))
			{
				return true;
			}
			if (is_negative(s1) && !is_negative(s2))
			{
				return false;
			}

			bool flag = true;

			if (is_negative(s1) && is_negative(s2))
			{
				s1 = get_abs(s1);
				s2 = get_abs(s2);
				flag = false;
			}

			if (s1.size() > s2.size())
			{
				return flag;
			}
			if (s1.size() < s2.size())
			{
				return !flag;
			}
			
			for (int i = 0; i < s1.size(); i++)
			{
				if ((s1[i] - '0') > (s2[i] - '0'))
				{
					return flag;
				}
				if ((s1[i] - '0') < (s2[i] - '0'))
				{
					return !flag;
				}
			}

			return false;
		}


		bool is_less(string s1, string s2)
		{
			if (is_negative(s1) && !is_negative(s2))
			{
				return true;
			}
			if (!is_negative(s1) && is_negative(s2))
			{
				return false;
			}

			bool flag = true;

			if (is_negative(s1) && is_negative(s2))
			{
				s1 = get_abs(s1);
				s2 = get_abs(s2);
				flag = false;
			}

			if (s1.size() < s2.size())
			{
				return flag;
			}
			if (s1.size() > s2.size())
			{
				return !flag;
			}

			for (int i = 0; i < s1.size(); i++)
			{
				if ((s1[i] - '0') < (s2[i] - '0'))
				{
					return flag;
				}
				if ((s1[i] - '0') > (s2[i] - '0'))
				{
					return !flag;
				}
			}

			return false;
		}


		bool is_equal(string s1, string s2)
		{
			if (s1.size() != s2.size())
			{
				return false;
			}

			for (int i = 0; i < s1.size(); i++)
			{
				if (s1[i] != s2[i])
				{
					return false;
				}
			}

			return true;
		}
	

	public:
		BigNumber()
		{
			this->value = "0";
		}
		
		
		BigNumber(const char value[])
		{
			this->operator=(value);
		}


		BigNumber(const BigNumber& bnum)
		{
			this->value = bnum.value;
		}
		

		BigNumber(string& str)
		{
			this->value = str;
		}


		template<class s>
		BigNumber(const s value)
		{
			this->value = to_string(value);
		}


		friend ostream& operator<<(ostream& os, const BigNumber& number);
		
		
		friend istream& operator>>(istream& os, BigNumber& number);
	
		
		BigNumber& operator=(const BigNumber& bnum)
		{
			this->value = bnum.value;

			return *this;
		}
		
		
		BigNumber& operator=(const char* value)
		{
			this->value = value;

			return *this;
		}


		template<class s>
		BigNumber& operator=(const s& value)
		{
			this->value = to_string(value);

			return *this;
		}


		BigNumber operator+(const BigNumber& bnum)
		{
			BigNumber reply;
		    reply.value = get_sum(this->value, bnum.value);
			
			return reply;
		}


		BigNumber operator+(const char* value)
		{
			BigNumber bnum;
			bnum.value = get_sum(this->value, value);

			return bnum;
		}


		template<class s>
		BigNumber operator+(const s& value)
		{
			BigNumber bnum;
			bnum.value = get_sum(this->value, to_string(value));

			return bnum;
		}


		BigNumber operator-(const BigNumber& bnum)
		{
			BigNumber reply;
			reply.value = get_difference(this->value, bnum.value);

			return reply;
		}


		BigNumber operator-(const char* value)
		{
			BigNumber reply;
			reply.value = get_difference(this->value, value);

			return reply;
		}


		template<class s>
		BigNumber operator-(const s& value)
		{
			BigNumber reply;
			reply.value = get_difference(this->value, to_string(value));

			return reply;
		}
		

		BigNumber operator*(const BigNumber& bnum)
		{
			BigNumber reply;
			reply.value = get_product(this->value, bnum.value);

			return reply;
		}

		
		BigNumber operator*(const char* value)
		{
			BigNumber reply;
			reply.value = get_product(this->value, value);

			return reply;
		}


		template<class s>
		BigNumber operator*(const s& value)
		{
			BigNumber reply;
			reply.value = get_product(this->value, to_string(value));

			return reply;
		}
		

		BigNumber operator/(const BigNumber& bnum)
		{
			BigNumber reply;
			reply.value = get_quotient(this->value, bnum.value);

			return reply;
		}


		BigNumber operator/(const char* value)
		{
			BigNumber reply;
			reply.value = get_quotient(this->value, value);

			return reply;
		}


		template<class s>
		BigNumber operator/(const s& value)
		{
			BigNumber reply;
			reply.value = get_quotient(this->value, to_string(value));

			return reply;
		}


		BigNumber operator%(const BigNumber& bnum)
		{
			BigNumber reply;
			reply.value = get_reminder(this->value, bnum.value);

			return reply;
		}


		BigNumber operator%(const char* value)
		{
			BigNumber reply;
			reply.value = get_reminder(this->value, value);

			return reply;
		}


		template<class s>
		BigNumber operator%(const s& value)
		{
			BigNumber reply;
			reply.value = get_reminder(this->value, to_string(value));

			return reply;
		}


		BigNumber& operator+=(const BigNumber& bnum)
		{
			this->value = get_sum(this->value, bnum.value);

			return *this;
		}


		BigNumber& operator+=(const char* value)
		{
			this->value = get_sum(this->value, value);

			return *this;
		}


		template<class s>
		BigNumber& operator+=(const s& value)
		{
			this->value = get_sum(this->value, to_string(value));

			return *this;
		}


		BigNumber& operator-=(const BigNumber& bnum)
		{
			this->value = get_difference(this->value, bnum.value);

			return *this;
		}


		BigNumber& operator-=(const char* value)
		{
			this->value = get_difference(this->value, value);

			return *this;
		}

		
		template<class s>
		BigNumber& operator-=(const s& value)
		{
			this->value = get_difference(this->value, to_string(value));

			return *this;
		}

		
		BigNumber& operator*=(const BigNumber& bnum)
		{
			this->value = get_product(this->value, bnum.value);

			return *this;
		}


		BigNumber& operator*=(const char* value)
		{
			this->value = get_product(this->value, value);

			return *this;
		}


		template<class s>
		BigNumber& operator*=(const s& value)
		{
			this->value = get_product(this->value, to_string(value));
			
			return *this;
		}


		BigNumber& operator/=(const BigNumber& bnum)
		{
			this->value = get_quotient(this->value, bnum.value);

			return *this;
		}


		BigNumber& operator/=(const char* value)
		{
			this->value = get_quotient(this->value, value);

			return *this;
		}
		

		template<class s>
		BigNumber& operator/=(const s& value)
		{
			this->value = get_quotient(this->value, to_string(value));

			return *this;
		}


		BigNumber& operator%=(const BigNumber& bnum)
		{
			this->value = get_reminder(this->value, bnum.value);

			return *this;
		}


		BigNumber& operator%=(const char* value)
		{
			this->value = get_reminder(this->value, value);

			return *this;
		}


		template<class s>
		BigNumber& operator%=(const s& value)
		{
			this->value = get_reminder(this->value, to_string(value));

			return *this;
		}


		BigNumber operator-()
		{
			BigNumber bnum;
			if (!is_negative(this->value) && (this->value != "0"))
			{
				bnum.value = "-" + this->value;
				return bnum;
			}
			bnum.value = get_abs(this->value);
			return bnum;
		}


		BigNumber& operator++()
		{
			this->value = get_sum(this->value, "1");

			return *this;
		}

		
		BigNumber operator++(int)
		{
			BigNumber bnum;
			bnum.value = this->value;

			this->value = get_sum(this->value, "1");

			return bnum;
		}


		BigNumber& operator--()
		{
			this->value = get_difference(this->value, "1");

			return *this;
		}


		BigNumber operator--(int)
		{
			BigNumber bnum;
			bnum.value = this->value;

			this->value = get_difference(this->value, "1");

			return bnum;
		}


		bool operator<(const BigNumber& bnum)
		{
			return is_less(this->value, bnum.value);
		}


		bool operator<=(const BigNumber& bnum)
		{
			return is_less(this->value, bnum.value) || is_equal(this->value, bnum.value);
		}


		bool operator>(const BigNumber& bnum)
		{
			return is_greater(this->value, bnum.value);
		}


		bool operator>=(const BigNumber& bnum)
		{
			return is_greater(this->value, bnum.value) || is_equal(this->value, bnum.value);
		}


		bool operator==(const BigNumber& bnum)
		{
			return is_equal(this->value, bnum.value);
		}


		bool operator!=(const BigNumber& bnum)
		{
			return !is_equal(this->value, bnum.value);
		}


		bool operator<(const char* value)
		{
			return is_less(this->value, value);
		}


		bool operator<=(const char* value)
		{
			return is_less(this->value, value) || is_equal(this->value, value);
		}


		bool operator>(const char* value)
		{
			return is_greater(this->value, value);
		}


		bool operator>=(const char* value)
		{
			return is_greater(this->value, value) || is_equal(this->value, value);
		}


		bool operator==(const char* value)
		{
			return is_equal(this->value, value);
		}


		bool operator!=(const char* value)
		{
			return !is_equal(this->value, value);
		}


		template<class s>
		bool operator<(const s& value)
		{
			return is_less(this->value, to_string(value));
		}


		template<class s>
		bool operator<=(const s& value)
		{
			string string_value = to_string(value);
			return is_less(this->value, string_value) || is_equal(this->value, string_value);
		}


		template<class s>
		bool operator>(const s& value)
		{
			return is_greater(this->value, to_string(value));
		}

		
		template<class s>
		bool operator>=(const s& value)
		{
			string string_value = to_string(value);
			return is_greater(this->value, string_value) || is_equal(this->value, string_value);
		}


		template<class s>
		bool operator==(const s& value)
		{
			return is_equal(this->value, to_string(value));
		}


		template<class s>
		bool operator!=(const s& value)
		{
			return !is_equal(this->value, to_string(value));
		}
};


ostream& operator<<(ostream& os, const BigNumber& number)
{
	os << number.value;
	return os;
}


istream& operator>>(istream& os, BigNumber& number)
{
	os >> number.value;
	return os;
}


BigNumber max(BigNumber num1, BigNumber num2)
{
	if (num1 < num2)
	{
		return num2;
	}
	return num1;
}


BigNumber min(BigNumber num1, BigNumber num2)
{
	if (num1 < num2)
	{
		return num1;
	}
	return num2;
}


BigNumber abs(BigNumber num)
{
	if (num < 0)
	{
		return -num;
	}
	return num;
}


BigNumber sqrt(BigNumber num)
{
	if (num < 0)
	{
		return -1;
	}

	BigNumber l = 0, r = num;

	while (r - l > 1)
	{
		BigNumber m = (l + r) / 2;

		if (m * m > num)
		{
			r = m;
		}
		else
		{
			l = m;
		}
	}

	return l;
}
