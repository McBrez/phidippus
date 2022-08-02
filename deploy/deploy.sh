REPO_ROOT=../

# Copy the web folder into the build context.
cp -r $REPO_ROOT/web/ $REPO_ROOT/deploy/docker/apache/web/
# Build and run the web_server
docker container rm -f web_server
docker build -t phidippus_web_server $REPO_ROOT/deploy/docker/apache/
docker run -dit --name web_server -p 80:80 phidippus_web_server
