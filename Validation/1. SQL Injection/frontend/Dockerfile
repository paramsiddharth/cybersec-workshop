FROM node:15 as build

WORKDIR /app

ARG VITE_BACKEND

COPY package*.json /app
RUN npm install

ADD . /app
RUN npm run build

FROM httpd

COPY apache.conf /usr/local/apache2/conf/httpd.conf
COPY --from=build /app/dist /usr/local/apache2/htdocs