import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.FlowPane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class FirstJavaFX extends Application {
    @Override
    public void start(Stage primaryStage) {
        Label messageLabel = new Label("Welcome to JavaFX programming");
        messageLabel.setTextFill(Color.MAGENTA);
        FlowPane root = new FlowPane();
        root.setHgap(10);
        root.setVgap(10);
        root.getChildren().add(messageLabel);
        Scene scene = new Scene(root, 500, 200);
        primaryStage.setScene(scene);
        primaryStage.setTitle("This is the first JavaFX Application");
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}