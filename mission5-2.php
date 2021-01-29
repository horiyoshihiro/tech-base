<!DOCTYPE html>
<html lang="ja">
    <meta charset="UTF-8">
    <head>
        <title>mission5-1.php</title>
    </head>
    <body>
        <?php
        error_reporting(E_ALL & ~E_NOTICE);
        //データベース接続
        $dsn = 'mysql:dbname=*******;host=localhost';
        $user = '*******';
        $password = '********';
        $pdo = new PDO($dsn, $user, $password, array(PDO::ATTR_ERRMODE =>PDO::ERRMODE_WARNING));
        
        //テーブル作成
    	$sql = "CREATE TABLE IF NOT EXISTS mission5_text"
	    ." ("
	    . "id INT AUTO_INCREMENT PRIMARY KEY,"
	    . "name char(32),"
	    . "comment TEXT,"
	    . "date DATETIME,"
	    . "password varchar(16),"
	    . "deleteornot INT"
	    .");";
    	$stmt = $pdo->query($sql);
    	
    	//存在するテーブルの名前表示
    	//$sql = 'SHOW TABLES';
    	//$res = $pdo -> query($sql);
    	//foreach($res as $res){
    	//    echo $res[0];
    	//    echo '<br>';
    	//}
    	echo "<hr>";
    	
    	
        ?>
        <?php
        error_reporting(E_ALL & ~E_NOTICE);
        $name=$_POST["name"];
        $name=trim($name);
        $comment=$_POST["text"];
        $comment=trim($comment);
        $submit=$_POST["submit"];
        $number_d=$_POST["number_d"];
        $submit_d=$_POST["submit_d"];
        $number_e=$_POST["number_e"];
        $submit_e=$_POST["submit_e"];
        $password=$_POST["password"];
        $password=trim($password);
        $text_num_e=$_POST["text_num_e"];
        $text_num_e=trim($text_num_e);

        
        //1は新規投稿、2は編集投稿、3は削除、4は編集
        //フラグ建築：新規投稿と編集投稿
        if($submit!=NULL){
            if($name!=NULL && $comment!=NULL && $password!=NULL){
                if($text_num_e==NULL){
                    $f = 1;
                }else{
                    $f = 2;
                }
            }elseif($name==NULL){
                $erma = 1;//error messageのこと。エラーメッセージ表示を参照。
            }elseif($comment==NULL){
                $erma = 2;
            }elseif($password==NULL){
                $erma = 3;
            }
        }
        //フラグ建築：削除
        if($submit_d!=NULL){
            if($number_d!=NULL && $password!=NULL){
                $sql = 'SELECT password FROM mission5_text WHERE id = :id';
                $stmt = $pdo->prepare($sql);
                $stmt ->bindParam(':id', $number_d, PDO::PARAM_INT);
                $stmt ->execute();
                $results = $stmt ->fetch(PDO::FETCH_BOTH);
                if($results[0]===$password){
                    $f = 3;
                }else{
                    $erma = 4;
                }
            }elseif($number_d==NULL){
                $erma = 5;
            }elseif($password==NULL){
                $erma = 3;
            }
        }
        //フラグ建築：編集
        if($submit_e!=NULL){
            if($number_e!=NULL && $password!=NULL){
                $sql = 'SELECT password, deleteornot FROM mission5_text WHERE id = :id';
                $stmt = $pdo->prepare($sql);
                $stmt ->bindParam(':id', $number_e, PDO::PARAM_INT);
                $stmt ->execute();
                $results = $stmt ->fetch(PDO::FETCH_BOTH);
                if($results[0]===$password && $results[1]!=1){
                    $f = 4;
                }elseif($results[1]==1){
                    $erma = 6;
                }else{
                    $erma = 4;
                }
            }elseif($number_e==NULL){
                $erma = 5;
            }elseif($password==NULL){
                $erma = 3;
            }
        }
        
        ?>
        
        
        
        あなたはネコ派ですか？犬派ですか？<br>
        理由も一緒に書いてください！<br>
        <form action="" method="post">
            【投稿用フォーム】<br>
            本文を入力してください<br>
              
            名前：　<input type="text" name="name"  value="
            
            <?php error_reporting(E_ALL & ~E_NOTICE);
                if($f == 4){
                    $sql = 'SELECT name FROM mission5_text WHERE id = :id';
                    $stmt = $pdo->prepare($sql);
                    $stmt ->bindParam(':id', $number_e, PDO::PARAM_INT);
                    $stmt ->execute();
                    $results = $stmt->fetch(PDO::FETCH_BOTH);
                    echo $results[0];
                }
            ?>
            " ><br>
            
            本文：　<input type="text" name="text" value="
            <?php error_reporting(E_ALL & ~E_NOTICE);
                if($f == 4){
                    $sql = 'SELECT comment FROM mission5_text WHERE id = :id';
                    $stmt = $pdo->prepare($sql);
                    $stmt ->bindParam(':id', $number_e, PDO::PARAM_INT);
                    $stmt ->execute();
                    $results = $stmt->fetch(PDO::FETCH_BOTH);
                    echo $results[0];
                }    
            ?>"><br>
            パスワード：　<input type="text" name="password"><br>
            
            
            <input type="submit" name="submit">
            <input type="hidden" name="text_num_e" value=" 
            <?php error_reporting(E_ALL & ~E_NOTICE);
                if($f == 4){
                    echo $number_e;
                }            
            ?> 
            ">
            
            
            
            
          
        
            
        </form><br>    
            
        <form action="" method="post">
            【削除用フォーム】<br>
            削除する投稿の番号を入力してください<br>
            <input type="number" name="number_d" placeholder="数字を入力してください"><br>
            パスワード：　<input type="text" name="password">
            <input type="submit" name="submit_d" value="削除" >
            
          
        </form><br>
        
        <form action="" method="post">
            【編集用フォーム】<br>
            編集したい投稿番号を入力してください<br>
            
            <input type="number" name="number_e" placeholder="数字を入力してください"><br>
            パスワード：　<input type="text" name="password">
            <input type="submit" name="submit_e" value="編集" >
        </form><br><br>
    
        <?php
        error_reporting(E_ALL & ~E_NOTICE);
        $date=date("Y-m-d H:i:s");
        $name=$_POST["name"];
        $name=trim($name);
        $comment=$_POST["text"];
        $comment=trim($comment);
        $submit=$_POST["submit"];
        $number_d=$_POST["number_d"];
        $submit_d=$_POST["submit_d"];
        $number_e=$_POST["number_e"];
        $submit_e=$_POST["submit_e"];
        $text_num_e=$_POST["text_num_e"];
        $text_num_e=trim($text_num_e);
        $password=$_POST["password"];
        $password=trim($password);
        
        
        //エラーメッセージ表示
        if($erma==1){
            echo "名前が空欄です";
        }elseif($erma==2){
            echo "本文が空欄です";
        }elseif($erma==3){
            echo "パスワードが空欄です";
        }elseif($erma==4){
            echo "誤ったパスワードです";
        }elseif($erma==5){
            echo "数字が空欄です";
        }elseif($erma==6){
            echo "既に削除されています";
        }
        echo "<br>"."<hr>";
       
        //投稿ファイルの投稿番号の設定と新規投稿の書き込み
        if($f==1){
            $sql = $pdo -> prepare("INSERT INTO mission5_text (name, comment, date, password) 
            VALUES (:name, :comment, :date, :password)");
            $sql -> bindParam(':name', $name, PDO::PARAM_STR);
            $sql -> bindParam(':comment', $comment, PDO::PARAM_STR);
            $sql -> bindParam(':date', $date, PDO::PARAM_STR);
            $sql -> bindParam(':password', $password, PDO::PARAM_STR);
            $sql -> execute();
            echo "書き込みました","<br>"."<hr>";
        }
        
        
        //削除番号を記録
        if($f==3){
            $id = $number_d;
            $deleteornot = 1;//1は消去、nullはそのまま
            
            $sql = 'UPDATE mission5_text SET deleteornot=:deleteornot WHERE id=:id';
            $stmt = $pdo->prepare($sql);
            $stmt->bindParam(':deleteornot', $deleteornot, PDO::PARAM_INT);
            $stmt->bindParam(':id', $id, PDO::PARAM_INT);
            $stmt->execute();
            echo "削除しました"."<br>"."<hr>";
        }   
    
    
        //編集機能
         if($f==2){
            $id = $text_num_e;
            
            $sql = 'UPDATE mission5_text SET name=:name,comment=:comment,date=:date, password=:password 
            WHERE id=:id';
            $stmt = $pdo->prepare($sql);
            $stmt->bindParam(':name', $name, PDO::PARAM_STR);
            $stmt->bindParam(':comment', $comment, PDO::PARAM_STR);
            $stmt->bindParam(':date', $date, PDO::PARAM_STR);
            $stmt->bindParam(':password', $password, PDO::PARAM_STR);
            $stmt->bindParam(':id', $id, PDO::PARAM_INT);
            $stmt->execute();
            echo "編集しました"."<br>"."<hr>";
            
        }
        
        
        //DB内容をウェブページに出力
        $sql = 'SELECT * FROM mission5_text';
        $stmt = $pdo->query($sql);
        $results = $stmt->fetchAll();
        foreach ($results as $row){
            //削除済みか出力するか判断
            if($row['deleteornot'] != 1){
                echo $row['id'].',';
                echo $row['name'].',';
                echo $row['comment'].',';
                echo $row['date'].',';
                echo $row['password'].',';
                echo $row['deleteornot']. '<br>';
                echo "<hr>";
            }else{
                echo "削除済み"."<br>";
                echo "<hr>";
            }
		    
	    }
            
        ?>
    </body>
</html>