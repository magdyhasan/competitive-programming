#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


const int maxn = 410;

char numstr[maxn];


// big int from http://www.csdn123.com/html/blogs/20131017/84671.htm
struct bign
{
	int len, s[maxn];

	bign()
	{
		memset(s, 0, sizeof(s));
		len = 1;
	}

	bign(int num)
	{
		*this = num;
	}

	bign(const char* num)
	{
		*this = num;
	}

	bign operator = (const int num)
	{
		char s[maxn];
		sprintf(s, "%d", num);
		*this = s;
		return *this;
	}

	bign operator = (const char* num)
	{
		len = strlen(num);
		for (int i = 0; i < len; i++) s[i] = num[len - i - 1] & 15;
		return *this;
	}

	const char* str() const
	{
		if (len)
		{
			for (int i = 0; i < len; i++)
				numstr[i] = '0' + s[len - i - 1];
			numstr[len] = '\0';
		}
		else strcpy(numstr, "0");
		return numstr;
	}

	void clean()
	{
		while (len > 1 && !s[len - 1]) len--;
	}

	bign operator + (const bign& b) const
	{
		bign c;
		c.len = 0;
		for (int i = 0, g = 0; g || i < max(len, b.len); i++)
		{
			int x = g;
			if (i < len) x += s[i];
			if (i < b.len) x += b.s[i];
			c.s[c.len++] = x % 10;
			g = x / 10;
		}
		return c;
	}

	bign operator - (const bign& b) const
	{
		bign c;
		c.len = 0;
		for (int i = 0, g = 0; i < len; i++)
		{
			int x = s[i] - g;
			if (i < b.len) x -= b.s[i];
			if (x >= 0) g = 0;
			else
			{
				g = 1;
				x += 10;
			}
			c.s[c.len++] = x;
		}
		c.clean();
		return c;
	}

	bign operator * (const bign& b) const
	{
		bign c;
		c.len = len + b.len;
		for (int i = 0; i < len; i++)
			for (int j = 0; j < b.len; j++)
				c.s[i + j] += s[i] * b.s[j];
		for (int i = 0; i < c.len - 1; i++)
		{
			c.s[i + 1] += c.s[i] / 10;
			c.s[i] %= 10;
		}
		c.clean();
		return c;
	}

	bign operator / (const bign &b) const
	{
		bign ret, cur = 0;
		ret.len = len;
		for (int i = len - 1; i >= 0; i--)
		{
			cur = cur * 10;
			cur.s[0] = s[i];
			while (cur >= b)
			{
				cur -= b;
				ret.s[i]++;
			}
		}
		ret.clean();
		return ret;
	}

	bign operator % (const bign &b) const
	{
		bign c = *this / b;
		return *this - c * b;
	}

	bool operator < (const bign& b) const
	{
		if (len != b.len) return len < b.len;
		for (int i = len - 1; i >= 0; i--)
			if (s[i] != b.s[i]) return s[i] < b.s[i];
		return false;
	}

	bool operator > (const bign& b) const
	{
		return b < *this;
	}

	bool operator <= (const bign& b) const
	{
		return !(b < *this);
	}

	bool operator >= (const bign &b) const
	{
		return !(*this < b);
	}

	bool operator == (const bign& b) const
	{
		return !(b < *this) && !(*this < b);
	}

	bool operator != (const bign &a) const
	{
		return *this > a || *this < a;
	}

	bign operator += (const bign &a)
	{
		*this = *this + a;
		return *this;
	}

	bign operator -= (const bign &a)
	{
		*this = *this - a;
		return *this;
	}

	bign operator *= (const bign &a)
	{
		*this = *this * a;
		return *this;
	}

	bign operator /= (const bign &a)
	{
		*this = *this / a;
		return *this;
	}

	bign operator %= (const bign &a)
	{
		*this = *this % a;
		return *this;
	}
} f[1005];

int main(){
    f[1] = 2, f[2] = 5, f[3] = 13;
    for(int i=4;i<=1000;i++)
        f[i] = f[i-1]*2+f[i-2]+f[i-3];
    int n;
    while(scanf("%d",&n)!=EOF){
        puts(f[n].str());
    }
}
