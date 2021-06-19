FROM adoptopenjdk:16-jdk AS build

WORKDIR /app
ADD . /app

RUN ./mvnw clean package

FROM adoptopenjdk:16-jre

COPY --from=build /app/target/game-0.0.1-SNAPSHOT.jar /app/game.jar

CMD ["java", "-jar", "/app/game.jar"]