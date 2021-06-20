FROM node:15

USER node
WORKDIR /home/node

ADD --chown=node:node package*.json /home/node

RUN npm install --only=production

ADD --chown=node:node . /home/node

CMD [ "npm", "start" ]