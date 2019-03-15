
void Map::buildMatrix(){
    m_data = new char *[m_rows];
    for(int i = 0; i < m_rows; i++)
    {
        m_data[i] = new char[m_cols];
    }
}

void Map::deleteMatrix(){
    for(int i = 0; i < m_rows; i++){
        delete[] m_data[i];
    }
    delete[] m_data;
    m_data = nullptr;
}

void Map::fillMatrix(){
    for(int r = 0; r < m_rows; r++){
        for(int c = 0; c < m_cols; c++){
            m_data[r][c] = ' '; //Clearing everything
        }
    }
    //Creating border
    for(int c = 0; c < m_cols; c++){
        m_data[0][c] = '-';
        m_data[(m_rows - 1)][c] = '-';
    }
    for(int r = 0; r < m_rows; r++){
        m_data[r][0] = '|';
        m_data[r][(m_cols - 1)] = '|';
    }
    m_data[0][0] = '+';
    m_data[0][(m_cols - 1)] = '+';
    m_data[(m_rows - 1)][0] = '+';
    m_data[(m_rows - 1)][(m_cols - 1)] = '+';

}

void Map::printMatrix(){
    for(int r = 0; r < m_rows; r++){
        for(int c = 0; c < m_cols; c++){
            cout << m_data[r][c] << " ";
        }
        cout << endl;
    }
}

void Map::placeMountains(){
    int rowLength = (rand() % 3) + 6;
    int colLength = (rand() % 3) + 6;
    int startRow = (rand() % (m_rows - 1)) + 1; //Top left corner
    int startCol = (rand() % (m_cols - 1)) + 1;//m_rows/cols keeps it in border, -2 + 1 keeps it off the border

    if(startRow + rowLength > (m_rows - 1)){
        rowLength = (m_rows - 1) - startRow;
    }
    if(startCol + colLength > (m_cols - 1)){
        colLength = (m_cols - 1) - startCol;
    }
    for(int r = startRow; r < (startRow + rowLength); r++){
        for(int c = startCol; c < (startCol + colLength); c++){
            m_data[r][c] = 'M';
        }
    }

}
