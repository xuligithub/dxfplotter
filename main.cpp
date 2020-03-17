#include <ui_mainwindow.h>
#include <view/mainwindow.h>
#include <model/application.h>

#include <QApplication>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
	QApplication qapp(argc, argv);
	qapp.setApplicationName("dxfplotter");
	qapp.setApplicationDisplayName("dxfplotter");

	QCommandLineParser parser;
	parser.addPositionalArgument("file", "input file");
	parser.process(qapp);

	const QString fileName = parser.positionalArguments().value(0, "");

	Model::Application app(fileName);

	View::MainWindow window(app);

	qapp.exec();
}
