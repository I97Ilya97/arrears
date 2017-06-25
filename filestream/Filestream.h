#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>	  

#include <iostream>





class TFilestream

{

protected:

	FILE *File;

	bool failbitFlag;

	bool eofFlag;

	bool appFlag;

	bool binaryFlag;




private:

	void openFile(const char *filename, std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out)

	{

		binaryFlag = mode & std::ios_base::binary;

		mode -= mode & std::ios_base::binary;

		std::string m;

		switch (mode)

		{

		case std::ios_base::in:

			m = "r";

			break;

		case std::ios_base::out:

			m = "w";

			break;

		case std::ios_base::ate | std::ios_base::out:

		case std::ios_base::app | std::ios_base::out:

			m = "a";

			break;

		case std::ios_base::in | std::ios_base::out:

			m = "r+";

			break;

		case std::ios_base::in | std::ios_base::out | std::ios_base::trunc:

			m = "w+";

			break;

		case std::ios_base::in | std::ios_base::out | std::ios_base::ate:

		case std::ios_base::in | std::ios_base::out | std::ios_base::app:

			m = "a+";

			break;

		default:

			failbitFlag = true;

			break;

		}

		if (mode & std::ios_base::app) appFlag = true;

		if (binaryFlag) m += 'b';



		File = fopen(filename, m.c_str());



		if (File == nullptr) failbitFlag = true;

	}



public:

	TFilestream() : File(nullptr), failbitFlag(false), appFlag(false), binaryFlag(false), eofFlag(false)

	{}



	TFilestream(const char *filename, std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out)

		: File(nullptr), failbitFlag(false), appFlag(false), binaryFlag(false), eofFlag(false)

	{

		openFile(filename, mode);

	}



	TFilestream(const TFilestream &fs) = delete;



	void open(const char *filename, const std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out)

	{

		openFile(filename, mode);

	}



	bool open() const

	{

		return (File == nullptr);

	}



	void close()

	{

		fclose(File);

		File = nullptr;

	}



	TFilestream& getline(char *s, const int n, const char delim)

	{

		if (n <= 0) return *this;

		for (size_t i = 0; i < n; ++i)

		{

			int ch = fgetc(File);

			if (ch == EOF || ch == delim)

			{

				if (ch == EOF) eofFlag = true;

				s[i] = '\0';

				break;

			}

			s[i] = ch;

		}

		s[n] = '\0';

		return *this;

	}



	TFilestream& getline(char *s, const int n)

	{

		return getline(s, n, '\n');

	}



	TFilestream& read(char *s, const int n)

	{

		if (n <= 0) return *this;

		char *str = new char[n + 1];

		for (size_t i = 0; i < n; ++i)

		{

			int ch = fgetc(File);

			if (ch == EOF)

			{

				eofFlag = true;

				break;

			}

			str[i] = ch;

		}

		s = str;

		return *this;

	}



	int tellg()	const

	{

		return ftell(File);

	}



	TFilestream& seekg(const size_t pos)

	{

		eofFlag = false;

		fseek(File, pos, SEEK_SET);

		return *this;

	}



	TFilestream& seekg(const int off, const std::ios_base::seekdir way)

	{

		eofFlag = false;

		switch (way)

		{

		case std::ios_base::beg:

		{

			fseek(File, off, SEEK_SET);

			break;

		}

		case std::ios_base::cur:

		{

			fseek(File, off, SEEK_CUR);

			break;

		}

		case std::ios_base::end:

		{

			fseek(File, off, SEEK_END);

			break;

		}

		}

	}



	TFilestream& put(const char c)

	{

		fputc(c, File);

		return *this;

	}



	TFilestream& write(const char *s, const int n)

	{

		fwrite(s, sizeof(char), n, File);

		return *this;

	}



	bool eof() const

	{

		return eofFlag;

	}



	TFilestream& operator<< (char val)

	{

		fprintf(File, "%c", val);

		return *this;

	}
	TFilestream& operator>> (char *val)

	{

		fscanf(File, "%s", val);

		return *this;

	}

	TFilestream& operator<< (char *val)

	{

		fprintf(File, "%s", val);

		return *this;

	}

	TFilestream& operator<< (bool val)

	{

		fprintf(File, "%d", val);

		return *this;

	}

	TFilestream& operator<< (short val)

	{

		fprintf(File, "%hd", val);

		return *this;

	}

	TFilestream& operator<< (unsigned short val)

	{

		fprintf(File, "%hdu", val);

		return *this;

	}

	TFilestream& operator<< (int val)

	{

		fprintf(File, "%d", val);

		return *this;

	}

	TFilestream& operator<< (unsigned int val)

	{

		fprintf(File, "%du", val);

		return *this;

	}

	TFilestream& operator<< (long val)

	{

		fprintf(File, "%ld", val);

		return *this;

	}

	TFilestream& operator<< (unsigned long val)

	{

		fprintf(File, "%ldu", val);

		return *this;

	}

	TFilestream& operator<< (float val)

	{

		fprintf(File, "%f", val);

		return *this;

	}

	TFilestream& operator<< (double val)

	{

		fprintf(File, "%lf", val);

		return *this;

	}

	TFilestream& operator<< (long double val)

	{

		fprintf(File, "%Lf", val);

		return *this;

	}

	TFilestream& operator<< (std::string &val)

	{

		this->operator<<(val.c_str());

		return *this;

	}



	TFilestream& operator>> (char &val)

	{

		fscanf(File, "%c", val);

		return *this;

	}

	

	TFilestream& operator>> (bool &val)

	{

		fscanf(File, "%d", val);

		return *this;

	}

	TFilestream& operator>> (short &val)

	{

		fscanf(File, "%hd", val);

		return *this;

	}

	TFilestream& operator>> (unsigned short &val)

	{

		fscanf(File, "%hdu", val);

		return *this;

	}

	TFilestream& operator>> (int &val)

	{

		fscanf(File, "%d", val);

		return *this;

	}



	TFilestream& operator>> (float &val)

	{

		fscanf(File, "%f", val);

		return *this;

	}


	TFilestream& operator>> (unsigned long &val)

	{

		fscanf(File, "%ldu", val);

		return *this;

	}


	TFilestream& operator>> (long &val)

	{

		fscanf(File, "%ld", val);

		return *this;

	}

	TFilestream& operator>> (std::string &val)

	{

		char buf[512];

		getline(buf, 511);

		val = std::string(buf);

		return *this;

	}

	

	TFilestream& operator>> (double &val)

	{

		fscanf(File, "%lf", val);

		return *this;

	}

	TFilestream& operator>> (long double &val)

	{

		fscanf(File, "%Lf", val);

		return *this;

	}

	TFilestream& operator>> (unsigned int &val)

	{

		fscanf(File, "%du", val);

		return *this;

	}
};