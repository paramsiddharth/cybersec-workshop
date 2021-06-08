FROM python

WORKDIR /app
COPY requirements.txt /app

RUN pip install -r requirements.txt

ADD . /app

EXPOSE 80

CMD ["gunicorn", "app:app", "-b", "0.0.0.0:80", "-w", "1"]