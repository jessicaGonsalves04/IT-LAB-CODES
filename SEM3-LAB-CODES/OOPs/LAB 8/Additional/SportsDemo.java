interface Sports {
    void getNumberOfGoals();
    void dispTeam();
}

class Hockey implements Sports {
    private String team1;
    private String team2;
    private int goalsTeam1;
    private int goalsTeam2;

    public Hockey(String team1, String team2, int goalsTeam1, int goalsTeam2) {
        this.team1 = team1;
        this.team2 = team2;
        this.goalsTeam1 = goalsTeam1;
        this.goalsTeam2 = goalsTeam2;
    }

    @Override
    public void getNumberOfGoals() {
        System.out.println("Hockey match result:");
        System.out.println(team1 + " - " + goalsTeam1);
        System.out.println(team2 + " - " + goalsTeam2);
    }

    @Override
    public void dispTeam() {
        if (goalsTeam1 > goalsTeam2) {
            System.out.println("The winning team is: " + team1);
        } else if (goalsTeam1 < goalsTeam2) {
            System.out.println("The winning team is: " + team2);
        } else {
            System.out.println("It's a draw!");
        }
    }
}

class Football implements Sports {
    private String teamA;
    private String teamB;
    private int goalsTeamA;
    private int goalsTeamB;

    public Football(String teamA, String teamB, int goalsTeamA, int goalsTeamB) {
        this.teamA = teamA;
        this.teamB = teamB;
        this.goalsTeamA = goalsTeamA;
        this.goalsTeamB = goalsTeamB;
    }

    @Override
    public void getNumberOfGoals() {
        System.out.println("Football match result:");
        System.out.println(teamA + " - " + goalsTeamA);
        System.out.println(teamB + " - " + goalsTeamB);
    }

    @Override
    public void dispTeam() {
        if (goalsTeamA > goalsTeamB) {
            System.out.println("The winning team is: " + teamA);
        } else if (goalsTeamA < goalsTeamB) {
            System.out.println("The winning team is: " + teamB);
        } else {
            System.out.println("It's a draw!");
        }
    }
}

public class SportsDemo {
    public static void main(String[] args) {
        Hockey hockeyMatch = new Hockey("TeamX", "TeamY", 3, 2);
        hockeyMatch.getNumberOfGoals();
        hockeyMatch.dispTeam();

        Football footballMatch = new Football("TeamA", "TeamB", 1, 1);
        footballMatch.getNumberOfGoals();
        footballMatch.dispTeam();
    }
}
