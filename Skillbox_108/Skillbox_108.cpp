#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;

//------------------------------------------------------------------------------------------------
class Track // Класс для хранения информации об аудиозаписи
{
public:
	// Конструктор
	Track(string title, tm creationDate, int durationInSeconds) 
	: title(title), creationDate(creationDate), durationInSeconds(durationInSeconds) 
	{
	}

	void printInfo() // Метод для вывода информации о треке
	{
		cout << "Заглавие: " << title << endl;

		// Преобразование tm в строку с помощью std::asctime
		char buffer[80]; // Размер буфера должен быть достаточным для хранения результата
		strftime(buffer, sizeof(buffer), "%c", &creationDate); // Форматирование даты и времени

		cout << "Дата создания: " << buffer;
		cout << " Продолжительность: " << durationInSeconds << " секунд" << endl;
	}
	
	string getTitle() const // Метод для получения названия трека
	{
		return title;
	}

private:
	string title;
	tm creationDate;
	int durationInSeconds;
};
//------------------------------------------------------------------------------------------------
class AudioPlayer // Класс для аудиоплеера
{
public:
	// Конструктор
	AudioPlayer() 
	: currentTrackIndex(0), isPlaying(false) 
	{
	}

	void addTrack(Track track) // Метод для добавления трека в плеер
	{
		tracks.push_back(track);
	}

	void play(const string& trackTitle) // Метод для воспроизведения трека
	{
		for (size_t i = 0; i < tracks.size(); ++i)
		{
			// Преобразование обеих строк к нижнему регистру для сравнения без учета регистра
			string trackTitleLower, trackNameLower;
			for (char c : trackTitle) trackTitleLower += tolower(c);
			for (char c : tracks[i].getTitle()) trackNameLower += tolower(c);

			if (trackTitleLower == trackNameLower)
			{
				tracks[i].printInfo();
				isPlaying = true;
				return;
			}
		}
		cout << "Трек не найден!" << endl;
	}

	void pause() // Метод для приостановки воспроизведения
	{
		if (isPlaying) 
		{
			cout << "Воспроизведение приостановлено." << endl;
			isPlaying = false;
		}
		else 
		{
			cout << "В данный момент ни один трек не воспроизводится." << endl;
		}
	}

	void next()
	{
		if (!tracks.empty()) // Метод для перехода к следующему треку
		{
			currentTrackIndex = rand() % tracks.size();
			tracks[currentTrackIndex].printInfo();
		}
		else 
		{
			cout << "Треки недоступны." << endl;
		}
	}

	void stop() // Метод для остановки воспроизведения
	{
		if (isPlaying) 
		{
			cout << "Воспроизведение остановлено." << endl;
			isPlaying = false;
		}
		else
		{
			cout << "В данный момент ни один трек не воспроизводится." << endl;
		}
	}

	void exit() // Метод для выхода из программы
	{
		cout << "Выход из программы." << endl;
	}

private:
	vector<Track> tracks;
	int currentTrackIndex;
	bool isPlaying;
};
//------------------------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL,"ru");

	// Создание объекта аудиоплеера
	AudioPlayer audioPlayer;

	tm date;
	date.tm_year = 121; // Год (год - 1900)
	date.tm_mon = 5;	  // Месяц (от 0 до 11)
	date.tm_mday = 5;   // День (от 1 до 31)
	date.tm_hour = 0;   // Час (от 0 до 23)
	date.tm_min = 0;    // Минута (от 0 до 59)
	date.tm_sec = 0;    // Секунда (от 0 до 59)

	audioPlayer.addTrack(Track("Dans", date, 180));   // Пример: трек длится 3 минуты (180 секунд)
	audioPlayer.addTrack(Track("disco", date, 240)); // Пример: трек длится 4 минуты (240 секунд)
	audioPlayer.addTrack(Track("Roc", date, 300));  // Пример: трек длится 5 минут (300 секунд)

	// Основной цикл программы
	while (true) 
	{
		cout << "Введите команду (play, pause, next, stop, exit): ";
		string command;
		cin >> command;

		// Обработка команд пользователя
		if (command == "play") 
		{
			string trackTitle;
			cout << "Введите название трека для воспроизведения: ";
			cin >> trackTitle;
			audioPlayer.play(trackTitle);
		}
		else if (command == "pause") 
		{
			audioPlayer.pause();
		}
		else if (command == "next") 
		{
			audioPlayer.next();
		}
		else if (command == "stop") 
		{
			audioPlayer.stop();
		}
		else if (command == "exit") 
		{
			audioPlayer.exit();
			break;
		}
		else 
		{
			cout << "Недопустимая команда. Пожалуйста, попробуйте снова." << endl;
		}
	}

	return 0;
}
//------------------------------------------------------------------------------------------------