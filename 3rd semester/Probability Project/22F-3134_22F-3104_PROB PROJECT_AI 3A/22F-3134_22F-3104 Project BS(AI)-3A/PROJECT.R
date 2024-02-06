library(shiny)
library(shinydashboard)
library(ggplot2)
library(DT)
getwd();
# Load data from CSV file
mydata <- read.csv("clinical.csv", header = TRUE)
class(mydata)
# Define UI
ui <- dashboardPage(
  dashboardHeader(title = "HEART FAIL DATA ANALYSIS"),
  dashboardSidebar(
    sidebarMenu(
      menuItem("Histogram", tabName = "histogram", icon = icon("bar-chart")),
      menuItem("Boxplot", tabName = "boxplot", icon = icon("th")),
      menuItem("Scatter Plot", tabName = "scatterplot",icon = icon("th")),
      menuItem("Analysis", tabName = "analysis", icon = icon("calculator"),
               menuSubItem("Age", tabName = "age_analysis"),
               menuSubItem("CP", tabName = "cp_analysis"),
               menuSubItem("Ejection Fraction", tabName = "ef_analysis")),
      menuItem("Normal distribution",tabname="normal",icon=icon("bell"),
               menuSubItem("CPK",tabName = "cpk_normal"),
               menuSubItem("Ejection fraction",tabName = "ej_normal")
      )
    )
  ),
  dashboardBody(
    tabItems(
      tabItem(tabName = "histogram",
              fluidPage(
                box(title = "Histogram of age", plotOutput("hist_plot1", height = "400px")),
                box(title = "Histogram of ejection fraction", plotOutput("hist_plot2", height = "400px")),
                box(title = "Histogram of cpk", plotOutput("hist_plot3", height = "400px")),
                h4("Summary :- "),
                h5("1) Histogram of age show that this data is normal."),
                h5("2) Histogram of creatinine_phosphokinase shows that this data not normal it is not bell shaped."),
                h5("3) Histogram of ejection fraction are also shows that data is normal.")

              )
      ),
      tabItem(tabName = "boxplot",
              fluidRow(
                box(title = "Boxplot of age", plotOutput("box_plot1", height = "400px")),
                box(title = "Boxplot of cpk", plotOutput("box_plot2", height = "400px")),
                box(title = "Boxplot ejection fraction", plotOutput("box_plot3", height = "400px")),
                h4("Summary :- "),
                h5("1) BOXPLOT of age show that this data is normal and it not have outliars."),
                h5("2) Boxplot of creatinine_phosphokinase shows that outliars are very much so uncertanty exist here"),
                h5("3) BOXPLOT of ejection fraction are also not have many outliars and data is in its ange.")
                
              )
      ),
      tabItem(tabName = "scatterplot",
              fluidRow(
                box(title = "Scatter Plot between ejection fraction and death", plotOutput("scatter_plot1", height = "400px")),
                box(title = "Scatter Plot between CPK and deathevent", plotOutput("scatter_plot2", height = "400px")),
                h3("Model Result :"),
                h5("1) Scatterplot of EF and death have inverse relationship if one decrease other increase."),
                h5("2) scatterplot of CPK and death at last have direct relationship.")
              )
      ),
      tabItem(tabName = "age_analysis",
              fluidRow(
                uiOutput("output_ui"),
                uiOutput("output_ui1"),
                uiOutput("output_ui2"),
                uiOutput("output_ui3")
                
              )
      ),
      tabItem(tabName = "cp_analysis",
              fluidRow(
                uiOutput("output_ui4"),
                uiOutput("output_ui5"),
                uiOutput("output_ui6"),
                uiOutput("output_ui7")
              )
      ),
      tabItem(tabName = "ef_analysis",
              fluidRow(
                uiOutput("output_ui8"),
                uiOutput("output_ui9"),
                uiOutput("output_ui10"),
                uiOutput("output_ui11")
              )
      ),
      tabItem(tabName = "ej_normal",
              fluidRow(
                sidebarLayout(
                  sidebarPanel(
                    numericInput("x", "Enter  value of x :", value = 0),
                    actionButton("submit", "Calculate"),
                    h4("Note :-"),
                    h5("take the zee score value and get probability from given table.")
                  ),
                  mainPanel(
                    h3("zee score of ejection fraction :"),
                    verbatimTextOutput("result"),
                    tags$img(src = "saad.png", height = "759px", width = "759px")
                  )
                )
                
               
              )
      ),tabItem(tabName = "cpk_normal",
                fluidRow(
                  sidebarLayout(
                    sidebarPanel(
                      numericInput("y", "Enter  value of x :", value = 0),
                      actionButton("submit", "Calculate"),
                      h4("Note :-"),
                      h5("take the zee score value and get probability from given table.")
                    ),
                    mainPanel(
                      h3("zee score of creatinine_phosphokinase:"),
                      verbatimTextOutput("result1"),
                      tags$img(src = "saad.png", height = "759px", width = "759px")
                    )
                  )
                )
      )  
      
      
      
    )
  )
  
)
# Define server
server <- function(input, output) {
  output$output_text23 <- renderText({
    h2("This is the output text.")
  })
  
  
  output$result <- renderPrint({
    normal_ejection(input$x)
  })
  
  output$result1 <- renderPrint({
    normal_cretanin(input$y)
  })
  
  normal_ejection <- function(v) {
    n <- length(mydata$ejection_fraction)
    for (i in 1:n) {
      if (i == v) {
        return(pnorm(mydata$ejection_fraction[i], mean(mydata$ejection_fraction), sd(mydata$ejection_fraction)))
      }
    }
    return(NA) # return NA if value not found
  }
  
  normal_cretanin <- function(v) {
    n <- length(mydata$creatinine_phosphokinase)
    for (i in 1:n) {
      if (i == v) {
        return(pnorm(mydata$creatinine_phosphokinase[i], mean(mydata$creatinine_phosphokinase), sd(mydata$creatinine_phosphokinase)))
      }
    }
    return(NA) # return NA if value not found
  }
  
  output$output_ui <- renderUI({
    mean_age <- age_mean()
    tags$div(
      h3("Mean Age:"),
      tags$p(mean_age)
    )
  })
  
  output$output_ui1 <- renderUI({
    median_age <- age_median()
    tags$div(
      h3("Median of age :"),
      tags$p(median_age)
    )
  })
  
  output$output_ui2 <- renderUI({
    var_age <- age_var()
    tags$div(
      h3("Variance of age :"),
      tags$p(var_age)
    )
  })
  
  output$output_ui3 <- renderUI({
    sd_age <- age_sd()
    tags$div(
      h3("Standard diviation of age :"),
      tags$p(sd_age)
    )
  })
  
  
  output$output_ui4 <- renderUI({
    mean_cpk <- cpk_mean()
    tags$div(
      h3("Mean of creatinine_phosphokinase :"),
      tags$p(mean_cpk)
    )
  })
  
  output$output_ui5 <- renderUI({
    median_cpk <- cpk_median()
    tags$div(
      h3("Median of creatinine_phosphokinase :"),
      tags$p(median_cpk)
    )
  })
  
  output$output_ui6 <- renderUI({
    var_cpk <- cpk_var()
    tags$div(
      h3("Variance of creatinine_phosphokinase :"),
      tags$p(var_cpk)
    )
  })
  
  output$output_ui7 <- renderUI({
    sd_cpk <- cpk_sd()
    tags$div(
      h3("Standard diviation of creatinine_phosphokinase :"),
      tags$p(sd_cpk)
    )
  })
  
  
  output$output_ui8 <- renderUI({
    mean_ejection <- ejection_mean()
    tags$div(
      h3("Mean of ejection_fraction :"),
      tags$p(mean_ejection)
    )
  })
  
  output$output_ui9 <- renderUI({
    median_ejection <- ejection_median()
    tags$div(
      h3("Median of ejection fraction :"),
      tags$p(median_ejection)
    )
  })
  
  output$output_ui10 <- renderUI({
    var_ejection <- ejection_var()
    tags$div(
      h3("Variance of ejection fraction :"),
      tags$p(var_ejection)
    )
  })
  
  output$output_ui11 <- renderUI({
    sd_ejection <- ejection_sd()
    tags$div(
      h3("Standard diviation of ejection fraction :"),
      tags$p(sd_ejection)
    )
  })
  
  
  
  # Render histogram subplots
  output$hist_plot1 <- renderPlot({
    ggplot(mydata, aes(x = age)) + geom_histogram(binwidth = 5)
  })
  output$hist_plot2 <- renderPlot({
    ggplot(mydata, aes(x = ejection_fraction)) + geom_histogram(binwidth = 2)
  })
  output$hist_plot3 <- renderPlot({
    ggplot(mydata, aes(x =creatinine_phosphokinase)) + geom_histogram(binwidth = 10)
  })
  
  # Render boxplot subplots
  output$box_plot1 <- renderPlot({
    ggplot(mydata, aes( y = age)) + geom_boxplot()
  })
  output$box_plot2 <- renderPlot({
    ggplot(mydata, aes( y =creatinine_phosphokinase )) + geom_boxplot()
  })
  output$box_plot3 <- renderPlot({
    ggplot(mydata, aes( y =ejection_fraction)) + geom_boxplot()
  })
  
  # Render scatter plot subplots
  output$scatter_plot1 <- renderPlot({
    ggplot(mydata, aes(x =ejection_fraction,y=DEATH_EVENT)) + geom_point()+geom_smooth()
  })
  output$scatter_plot2 <- renderPlot({
    ggplot(mydata, aes(x = creatinine_phosphokinase, y =DEATH_EVENT )) + geom_point()+geom_smooth()
  })
  
  
  age_mean<-function(){
    x<-mean(mydata$age)
    return (x)
  }
  
  age_median<-function(){
    return(median(mydata$age));
  }
  
  age_var<-function(){
    return(var(mydata$age))
  }
  
  age_sd<-function(){
    return (sd(mydata$age))
  }
  
  cpk_mean<-function(){
    x<-mean(mydata$creatinine_phosphokinase)
    return (x)
  }
  
  cpk_median<-function(){
    return(median(mydata$creatinine_phosphokinase));
  }
  
  cpk_var<-function(){
    return(var(mydata$creatinine_phosphokinase))
  }
  
  cpk_sd<-function(){
    return (sd(mydata$creatinine_phosphokinase))
  }
  
  ejection_mean<-function(){
    x<-mean(mydata$ejection_fraction)
    return (x)
  }
  
  ejection_median<-function(){
    return(median(mydata$ejection_fraction));
  }
  
  ejection_var<-function(){
    return(var(mydata$ejection_fraction))
  }
  
  ejection_sd<-function(){
    return (sd(mydata$ejection_fraction))
  }
  # Render mean and median tables
  output$mean_analysis <- renderText({
    mean_data <- data.frame(Age = mean(mydata$age), CP = mean(mydata$cp), Ejection_Fraction = mean(mydata$ejection_fraction))
    colnames(mean_data) <- c("Mean age", "Mean CP", "Mean Ejection Fraction")
    mean_data
  })
  
  output$median_analysis <- renderTable({
    median_data <- data.frame(Age = median(mydata$age), CP = median(mydata$cp), Ejection_Fraction = median(mydata$ejection_fraction))
    colnames(median_data) <- c("Median Age", "Median CP", "Median Ejection Fraction")
    median_data
  })
  
  # Render variance and standard deviation tables
  output$variance_analysis <- renderTable({
    var_data <- data.frame(Age = var(mydata$age), CP = variance_cp(mydata$cp), Ejection_Fraction = variance_ef(mydata$ejection_fraction))
    colnames(var_data) <- c("Variance Age", "Variance CP", "Variance Ejection Fraction")
    var_data
  })
  
  output$standarddeviation_analysis <- renderTable({
    sd_data <- data.frame(Age = standarddeviation(mydata$age), CP = standarddeviation_cp(mydata$cp), Ejection_Fraction = standarddeviation_ef(mydata$ejection_fraction))
    colnames(sd_data) <- c("Standard Deviation Age", "Standard Deviation CP", "Standard Deviation Ejection Fraction")
    sd_data
  })
  # render normal distribution
  output$normaldistribution_analysis <- renderTable({
    sd_data <- data.frame(CP = normaldistribution_cp(mydata$cp), Ejection_Fraction = normaldistribution_ef(mydata$ejection_fraction))
    colnames(sd_data) <- c("Normal Distribution CP", "Normal Distribution Ejection Fraction")
    sd_data
  })
  
  
}

shinyApp(ui, server)