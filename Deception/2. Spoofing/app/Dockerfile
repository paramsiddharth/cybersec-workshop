FROM node:15

USER node

WORKDIR /app

ADD --chown=node:node package*.json .
RUN npm ci --only=prod

ADD --chown=node:node . .

CMD ["npm", "start"]