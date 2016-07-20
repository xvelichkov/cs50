-- MySQL dump 10.13  Distrib 5.5.49, for debian-linux-gnu (x86_64)
--
-- Host: 0.0.0.0    Database: pset7
-- ------------------------------------------------------
-- Server version	5.5.49-0ubuntu0.14.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `history`
--

DROP TABLE IF EXISTS `history`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `history` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `symbol` varchar(255) NOT NULL,
  `shares` int(11) NOT NULL,
  `action` enum('Sell','Buy') NOT NULL,
  `price` decimal(65,2) NOT NULL,
  `date` datetime NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `history`
--

LOCK TABLES `history` WRITE;
/*!40000 ALTER TABLE `history` DISABLE KEYS */;
INSERT INTO `history` VALUES (1,9,'Facebook, Inc.','FB',1,'Buy',121.73,'2016-07-20 16:25:19'),(2,9,'Facebook, Inc.','FB',1,'Buy',121.73,'2016-07-20 16:25:45'),(4,9,'Facebook, Inc.','FB',1,'Sell',121.00,'2016-07-20 16:29:14'),(5,9,'Facebook, Inc.','FB',1,'Sell',121.86,'2016-07-20 16:29:47'),(6,9,'Alphabet Inc.','GOOG',20,'Buy',740.76,'2016-07-20 16:47:15'),(7,9,'Alphabet Inc.','GOOG',200,'Sell',740.73,'2016-07-20 16:49:07');
/*!40000 ALTER TABLE `history` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `portfolios`
--

DROP TABLE IF EXISTS `portfolios`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `portfolios` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) NOT NULL,
  `symbol` varchar(255) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `shares` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `user_id_2` (`user_id`,`symbol`),
  UNIQUE KEY `user_id` (`user_id`,`symbol`)
) ENGINE=InnoDB AUTO_INCREMENT=26 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `portfolios`
--

LOCK TABLES `portfolios` WRITE;
/*!40000 ALTER TABLE `portfolios` DISABLE KEYS */;
INSERT INTO `portfolios` VALUES (3,9,'GOOGL',100),(4,9,'GOOG',21),(6,9,'FB',28);
/*!40000 ALTER TABLE `portfolios` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(255) NOT NULL,
  `hash` varchar(255) NOT NULL,
  `cash` decimal(65,2) unsigned NOT NULL DEFAULT '0.00',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'andi','$2y$10$pKAhbA4v.T1gCEf6OuOIxekviWmNJj/ehNQ/PzO04rEb56Zetdjuu',10000.00),(2,'caesar','$2y$10$pKAhbA4v.T1gCEf6OuOIxekviWmNJj/ehNQ/PzO04rEb56Zetdjuu',10000.00),(3,'eli','$2y$10$pKAhbA4v.T1gCEf6OuOIxekviWmNJj/ehNQ/PzO04rEb56Zetdjuu',10000.00),(4,'hdan','$2y$10$pKAhbA4v.T1gCEf6OuOIxekviWmNJj/ehNQ/PzO04rEb56Zetdjuu',10000.00),(5,'jason','$2y$10$pKAhbA4v.T1gCEf6OuOIxekviWmNJj/ehNQ/PzO04rEb56Zetdjuu',10000.00),(6,'john','$2y$10$pKAhbA4v.T1gCEf6OuOIxekviWmNJj/ehNQ/PzO04rEb56Zetdjuu',10000.00),(7,'levatich','$2y$10$pKAhbA4v.T1gCEf6OuOIxekviWmNJj/ehNQ/PzO04rEb56Zetdjuu',10000.00),(8,'rob','$2y$10$pKAhbA4v.T1gCEf6OuOIxekviWmNJj/ehNQ/PzO04rEb56Zetdjuu',10000.00),(9,'skroob','$2y$10$pKAhbA4v.T1gCEf6OuOIxekviWmNJj/ehNQ/PzO04rEb56Zetdjuu',357394.88),(10,'zamyla','$2y$10$pKAhbA4v.T1gCEf6OuOIxekviWmNJj/ehNQ/PzO04rEb56Zetdjuu',10000.00);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-07-20 17:27:59
