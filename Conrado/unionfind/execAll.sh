echo "Cleaning data"
./clean.sh
echo "Executing Generator..."
./execGenerator.sh
echo "Executing Metrics..."
./execMetrics.sh
echo "Executing Time..."
./execTime.sh
echo "Done!"
