FROM alpine:latest

RUN apk add --update py-pip
RUN apk add --no-cache --update \
    python \
    python-dev \
    py-pip \
    build-base \
  && pip install virtualenv \
  && rm -rf /var/cache/apk/*

WORKDIR /app

EXPOSE 5000

COPY ./
ADD app.py /app/
ADD requirements.txt /app/

RUN pip install --upgrade pip
RUN pip install --trusted-host pypi.python.org -r requirements.txt


CMD ["python", "app.py"]