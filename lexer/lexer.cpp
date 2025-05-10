#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<cstring>
#include<unordered_map>
using namespace std;

int idNum = 0;
int litNum = 0;
int lineNum = 0;
const int BUFFER_SIZE = 25;

void PopulatingStatesAndChars(vector<string>& states, vector<string>& characters)
{
	states = {
		"S", "ST1", "SE", "NE1", "ST2", "GT1", "GE", "GT2",
		"cin", "mod", "or1", "or2", "and1", "and2", "E1", "E2",
		"ref", "E3", "NE4", "NE2", "NE3", "Star", "IC1", "IC2",
		"slash", "num2", "num1", "exp", "num4", "point", "minus1",
		"minus2", "ME", "minus3", "plus1", "PE", "plus2", "plus3",
		"col1", "col2", "semi", "cout", "punc", "ID1", "ID2",
		"ID3", "ID4", "inIf", "keyword", "point2", "point3"
	};
	characters = {
		"<", ">", "{", "}", "\"", ":", "=", "!", "&", "%", "*", "[", "/",
		")", "]", "(", "letter", "num", "+", "-", "_", ".", "E", "|", " ", "\\0"
	};
}

vector<int> acceptedStates(vector<string>& states)
{
	vector<int> arr(states.size(), 0);
	for (int i = 0; i < states.size(); i++)
	{
		if (states[i] == "ID4" || states[i] == "punc" || states[i] == "semi" || states[i] == "col2" || states[i] == "inIf" || states[i] == "cout" || states[i] == "SE" ||
			states[i] == "NE1" || states[i] == "ST2" || states[i] == "GE" || states[i] == "GT2" || states[i] == "cin" || states[i] == "mod" || states[i] == "or2" ||
			states[i] == "and2" || states[i] == "ref" || states[i] == "E2" || states[i] == "E3" || states[i] == "NE2" || states[i] == "NE3" || states[i] == "Star" ||
			states[i] == "IC1" || states[i] == "slash" || states[i] == "num2" || states[i] == "minus2" || states[i] == "ME" || states[i] == "minus3" || states[i] == "plus2" ||
			states[i] == "PE" || states[i] == "plus3" || states[i] == "keyword" || states[i] == "point3")
		{
			arr[i] = 1;
		}
	}
	return arr;
}

vector<vector<int>> PopulatingTransitionTable(int states, int characters)
{
	vector<vector<int>> transitionTable(states, vector<int>(characters, -1));
	transitionTable[0][0] = 1;
	transitionTable[0][1] = 5;
	transitionTable[0][9] = 9;
	transitionTable[0][8] = 12;
	transitionTable[0][23] = 10;
	transitionTable[0][6] = 14;
	transitionTable[0][7] = 18;
	transitionTable[0][10] = 21;
	transitionTable[0][4] = 22;
	transitionTable[0][12] = 24;
	transitionTable[0][5] = 38;
	transitionTable[0][2] = 42;
	transitionTable[0][3] = 42;
	transitionTable[0][11] = 42;
	transitionTable[0][13] = 42;
	transitionTable[0][14] = 42;
	transitionTable[0][15] = 42;
	transitionTable[0][20] = 44;
	transitionTable[0][16] = 43;
	transitionTable[0][18] = 34;
	transitionTable[0][19] = 30;
	transitionTable[0][17] = 26;
	transitionTable[38][5] = 40;
	transitionTable[38][6] = 39;
	for (int i = 0; i < characters; i++)
	{
		if (i != 5 && i != 6)
		{
			transitionTable[38][i] = 47;
		}
	}
	transitionTable[1][0] = 41;
	transitionTable[1][6] = 2;
	transitionTable[1][1] = 3;
	for (int i = 2; i < characters; i++)
	{
		if (i != 6)
		{
			transitionTable[1][i] = 4;
		}
	}
	transitionTable[5][6] = 6;
	transitionTable[5][1] = 8;
	for (int i = 0; i < characters; i++)
	{
		if (i != 1 && i != 6)
		{
			transitionTable[5][i] = 7;
		}
	}
	transitionTable[10][23] = 11;
	transitionTable[12][8] = 13;
	for (int i = 0; i < characters; i++)
	{
		if (i != 8)
		{
			transitionTable[12][i] = 16;
		}
	}
	transitionTable[14][6] = 15;
	transitionTable[18][6] = 19;
	for (int i = 0; i < characters; i++)
	{
		if (i != 6)
		{
			transitionTable[18][i] = 20;
		}
	}
	transitionTable[26][17] = 26;
	transitionTable[26][22] = 27;
	transitionTable[26][21] = 29;
	for (int i = 0; i < characters; i++)
	{
		if (i != 17 && i != 22 && i != 21)
		{
			transitionTable[26][i] = 25;
		}
	}
	transitionTable[27][17] = 26;
	transitionTable[27][18] = 28;
	transitionTable[27][19] = 28;
	transitionTable[28][17] = 26;
	transitionTable[29][17] = 49;
	transitionTable[30][17] = 26;
	transitionTable[30][6] = 32;
	transitionTable[30][19] = 33;
	for (int i = 0; i < characters; i++)
	{
		if (i != 17 && i != 6 && i != 19)
		{
			transitionTable[30][i] = 31;
		}
	}
	transitionTable[34][18] = 36;
	transitionTable[34][6] = 35;
	transitionTable[34][17] = 26;
	for (int i = 0; i < characters; i++)
	{
		if (i != 18 && i != 6 && i != 17)
		{
			transitionTable[34][i] = 37;
		}
	}
	transitionTable[44][17] = 44;
	transitionTable[44][16] = 44;
	transitionTable[44][20] = 44;
	for (int i = 0; i < characters; i++)
	{
		if (i != 17 && i != 16 && i != 20)
		{
			transitionTable[44][i] = 46;
		}
	}
	transitionTable[43][20] = 45;
	transitionTable[43][16] = 43;
	transitionTable[43][17] = 43;
	for (int i = 0; i < characters; i++)
	{
		if (i != 17 && i != 16 && i != 20)
		{
			transitionTable[43][i] = 48;
		}
	}
	transitionTable[45][17] = 45;
	transitionTable[45][16] = 45;
	transitionTable[45][20] = 45;
	transitionTable[49][17] = 49;
	transitionTable[49][22] = 27;
	for (int i = 0; i < characters; i++)
	{
		if (i != 17 && i != 22)
		{
			transitionTable[49][i] = 50;
		}
	}
	for (int i = 0; i < characters; i++)
	{
		if (i != 17 && i != 16 && i != 20)
		{
			transitionTable[45][i] = 46;
		}
	}
	return transitionTable;
}

vector<vector<int>> advancedTable(const vector<vector<int>> TT, vector<string>& states, int characters)
{
	vector<vector<int>> advTable(states.size(), vector<int>(characters, -1));
	for (int i = 0; i < states.size(); i++)
	{
		for (int j = 0; j < characters; j++)
		{
			if (TT[i][j] != -1)
			{
				if (states[TT[i][j]] == "ID4" || states[TT[i][j]] == "inIf" || states[TT[i][j]] == "GT2" || states[TT[i][j]] == "ST2" || states[TT[i][j]] == "ref" || states[TT[i][j]] == "E3" ||
					states[TT[i][j]] == "NE3" || states[TT[i][j]] == "num2" || states[TT[i][j]] == "minus2" || states[TT[i][j]] == "plus3" || states[TT[i][j]] == "keyword" || states[TT[i][j]] == "point3")
				{
					advTable[i][j] = 0;
				}
				else
				{
					advTable[i][j] = 1;
				}
			}
		}
	}
	return advTable;
}

bool checkError(char ch, char actualChar)
{
	if (ch == '@' || ch == '#' || ch == '$' || ch == '^')
	{
		ofstream file("error_22l6862.txt", ios::app);
		if (file.is_open()) {
			file << "Invalid Character '" << ch << "' at line number: " << lineNum << endl;
			file.close();
		}
		return true;
	}
	else if (ch == '~')
	{
		ofstream file("error_22l6862.txt", ios::app);
		if (file.is_open()) {
			file << "Invalid character '" << actualChar << "' at line number : " << lineNum << endl;
			file.close();
		}
		return true;
	}
	return false;
}

int getStateMap(string state, vector<string>& states)
{
	for (int i = 0; i < states.size(); i++)
	{
		if (states[i] == state)
		{
			return i;
		}
	}
	return -1;
}

int getCharMap(char ch, vector<string>& characters, string state)
{
	string what = "";
	if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
	{
		if (state == "num1" || state == "point" || state == "point2")
		{
			what = "E";
		}
		else if (state == "point2")
		{
			what = "E";
		}
		else
		{
			what = "letter";
		}
	}
	else if (ch >= '0' && ch <= '9')
	{
		what = "num";
	}
	else
	{
		what = ch;
	}
	for (int i = 0; i < characters.size(); i++)
	{
		if (characters[i] == what)
		{
			return i;
		}
	}
	return -1;
}

unordered_map<string, int> keywordHashmap()
{
	unordered_map<string, int> keywordMap = {
		{"asm", 1}, {"Wagarna", 2}, {"new", 3}, {"this", 4}, {"auto", 5}, {"enum", 6},
		{"operator", 7}, {"throw", 8}, {"Mantiqi", 9}, {"explicit", 10}, {"private", 11},
		{"True", 12}, {"break", 13}, {"export", 14}, {"protected", 15}, {"try", 16},
		{"case", 17}, {"extern", 18}, {"public", 19}, {"typedef", 20}, {"catch", 21},
		{"False", 22}, {"register", 23}, {"typeid", 24}, {"Harf", 25}, {"Ashriya", 26},
		{"typename", 27}, {"Adadi", 28}, {"class", 29}, {"for", 30}, {"Wapas", 31},
		{"union", 32}, {"const", 33}, {"dost", 34}, {"short", 35}, {"unsigned", 36},
		{"goto", 37}, {"signed", 38}, {"using", 39}, {"continue", 40}, {"Agar", 41},
		{"sizeof", 42}, {"virtual", 43}, {"default", 44}, {"inline", 45}, {"static", 46},
		{"Khali", 47}, {"delete", 48}, {"volatile", 49}, {"do", 50}, {"long", 51},
		{"struct", 52}, {"double", 53}, {"mutable", 54}, {"switch", 55}, {"while", 56},
		{"namespace", 57}, {"template", 58}, {"Marqazi", 59}, {"Matn", 60},
		{"input->", 61}, {"output<-", 62}
	};
	return keywordMap;
}

bool isAKeyword(string word, unordered_map<string, int> keywords)
{
	if (keywords.find(word) != keywords.end()) {
		return true;
	}
	return false;
}

int getKeywordMap(unordered_map<string, int> keywords, string word)
{
	for (const auto& pair : keywords) {
		if (pair.first == word)
		{
			return pair.second;
		}
	}
	return -1;
}

void removeComments(char IB[])
{
	string result;
	bool inBlockComment = false;
	bool inLineComment = false;
	size_t length = strlen(IB);

	for (size_t i = 0; i < length; i++)
	{
		if (!inBlockComment && !inLineComment && i + 1 < length && IB[i] == '/' && IB[i + 1] == '*')
		{
			inBlockComment = true;
			i++;
		}
		else if (inBlockComment && i + 1 < length && IB[i] == '*' && IB[i + 1] == '/')
		{
			inBlockComment = false;
			i++;
		}
		else if (!inBlockComment && !inLineComment && i + 1 < length && IB[i] == '/' && IB[i + 1] == '/')
		{
			inLineComment = true;
			i++;
		}
		else if (!inBlockComment && inLineComment && IB[i] == '\n')
		{
			inLineComment = false;
			result += IB[i];
		}
		else if (!inBlockComment && !inLineComment)
		{
			result += IB[i];
		}
	}
	strcpy_s(IB, result.length() + 1, result.c_str());
}

void makeWord(int startI, int endI, string& word, char* IB)
{
	for (int i = startI; i <= endI; i++)
	{
		word += IB[i];
	}
}

bool isAnIdentifier(vector<string>& characters, string word)
{
	for (int i = 0; i < characters.size(); i++)
	{
		if (characters[i] == word)
		{
			if (characters[i] != "letter" || characters[i] != "num" || characters[i] != "E")
			{
				return false;
			}
		}
	}
	return true;
}

bool alreadyAnIdentifier(unordered_map<string, int> identifiers, string word)
{
	for (const auto& pair : identifiers) {
		if (pair.first == word)
		{
			return true;
		}
	}
	return false;
}

int getIdMap(unordered_map<string, int> identifiers, string word)
{
	for (const auto& pair : identifiers)
	{
		if (pair.first == word)
		{
			return pair.second;
		}
	}
	return -1;
}

int getLitMap(unordered_map<string, int> literals, string word)
{
	for (const auto& pair : literals)
	{
		if (pair.first == word)
		{
			return pair.second;
		}
	}
	return -1;
}

void writeTokenOntoFile(string token)
{
	ofstream file("tokens_22l6862.txt", ios::app);
	if (file.is_open())
	{
		file << token;
		file.close();
	}
}

bool extractNextString(char* IB, int& offset, string& word)
{
	char* start = strchr(IB + offset, '"');
	if (!start) return false;
	char* end = strchr(start + 1, '"');
	if (!end) return false;
	int length = end - start - 1;
	char word1[100]{};
	strncpy_s(word1, start + 1, length);
	word1[length] = '\0';
	word = string(word1);
	offset = end - IB + 1;
	return true;
}

string readFileIntoString(const string& filename)
{
	ifstream file(filename);
	if (!file) {
		cerr << "Error: Could not open the file!" << endl;
		return "";
	}

	stringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();
}

char* processBuffers(const string& input, int& IB_size)
{
	int length = input.size();
	IB_size = length;
	char* IB = new char[IB_size + 1];
	char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
	int index = 0, IB_index = 0;
	bool toggle = true;
	while (index < length)
	{
		char* activeBuffer = toggle ? buffer1 : buffer2;
		int copySize = min(BUFFER_SIZE, length - index);
		memcpy(activeBuffer, input.data() + index, copySize);
		memcpy(IB + IB_index, activeBuffer, copySize);
		index += copySize;
		IB_index += copySize;
		toggle = !toggle;
	}
	IB[IB_size] = '\0';
	return IB;
}


void tokenization(string filename, vector<vector<int>> TT, vector<string>& states, vector<string>& characters, vector<int> accepted, vector<vector<int>> advTable, unordered_map<string, int> keywords)
{
	string input = readFileIntoString(filename);
	int IB_size = 0;
	char* IB = processBuffers(input, IB_size);
	cout << "Final IB Buffer: " << IB << std::endl;
	int offset = 0;
	removeComments(IB);
	unordered_map<string, int> identifiers;
	unordered_map<string, int> literals;
	for (int i = 0; i < IB_size && IB[i] != '\0'; i++)
	{
		if (IB[i] == ' ' || IB[i] == '\t' || IB[i] == '\n')
		{
			if (IB[i] == '\n')
			{
				lineNum++;
			}
			continue;
		}
		string token = "";
		string word = "";
		int state = getStateMap("S", states);
		int ch = getCharMap(IB[i], characters, "S");
		int startI = i;
		if (i < 1000)
		{
			i++;
		}
		else break;
		while (accepted[state] == 0 && !checkError(IB[i], IB[i]))
		{
			int newState = TT[state][ch];
			if (newState == -1)
			{
				if (checkError('~', IB[i - 2]))
				{
					i = i - (startI - i) - 3;
					break;
				}
			}
			if (advTable[state][ch] == 1)
			{
				ch = getCharMap(IB[i], characters, states[state]);
				if (IB[i] == '\0')
				{
					ch = 25;
				}
				if (i < IB_size)
				{
					i++;
				}
				else break;
			}
			state = newState;
		}
		if (accepted[state] == 1)
		{
			int litcount = 0;
			makeWord(startI, i - 2, word, IB);
			if (states[state] == "ID4")
			{
				if (!alreadyAnIdentifier(identifiers, word))
				{
					identifiers.insert({ word, idNum });
					token += "<id, ";
					token += to_string(idNum);
					token += ">";
					writeTokenOntoFile(token);
					cout << token << endl;
					ofstream file("sybmolTable_22l6862.txt", ios::app);
					if (file.is_open())
					{
						file << "pos: " << idNum << ",\t" << "lexeme: " << word << endl;
						file.close();
					}
					idNum++;
				}
				else
				{
					int id = getIdMap(identifiers, word);
					token += "<id, ";
					token += to_string(id);
					token += ">";
					writeTokenOntoFile(token);
					cout << token << endl;
				}
				if (i >= 2)
				{
					i -= 2;
				}
				else break;
			}
			else if (states[state] == "keyword")
			{
				if (IB[i - 1] == '<' && IB[i] == '-')
				{
					word = "";
					word = "output<-";
					i += 2;
				}
				else if (IB[i - 1] == '-' && IB[i] == '>')
				{
					word = "";
					word = "input->";
					i += 2;
				}
				if (isAKeyword(word, keywords))
				{
					token = "<res, ";
					token += to_string(getKeywordMap(keywords, word));
					token += ">";
					cout << token << endl;
					writeTokenOntoFile(token);
					if (i >= 2)
					{
						i -= 2;
					}
					else break;
				}
				else
				{
					cout << "Invalid identifier!" << endl;
					if (i >= 2)
					{
						i -= 2;
					}
					else break;
					continue;
				}
			}


			else if (states[state] == "IC1" || states[state] == "IC2")
			{
				extractNextString(IB, offset, word);
				literals.insert({ word, litNum });
				token += "<lit, ";
				token += to_string(litNum);
				token += ">";
				writeTokenOntoFile(token);
				cout << token << endl;
				ofstream file("literalTable_22l6862.txt", ios::app);
				if (file.is_open())
				{
					file << "pos: " << litNum << ",\t" << "lexeme: " << word << endl;
					file.close();
				}
				i += word.length();
				if (i >= 1)
				{
					i--;
				}
				else break;
				litNum++;
			}
			else
			{
				token = "<";
				token += word;
				token += ">";
				cout << token << endl;
				writeTokenOntoFile(token);
				if (i >= 2)
				{
					i -= 2;
				}
				else break;
			}
		}
	}
}

int main()
{
	vector<string> states, characters;
	PopulatingStatesAndChars(states, characters);
	vector<vector<int>> TT = PopulatingTransitionTable(states.size(), characters.size());
	vector<int> accepted = acceptedStates(states);
	vector<vector<int>> advTable = advancedTable(TT, states, characters.size());
	unordered_map<string, int> keywords = keywordHashmap();
	string filename = "22l6862_testCode.txt";
	tokenization(filename, TT, states, characters, accepted, advTable, keywords);
	cout << "Token written onto token.txt" << endl;
	return 0;
}