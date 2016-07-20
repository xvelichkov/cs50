/**
 * scripts.js
 *
 * Computer Science 50
 * Problem Set 7
 *
 * Global JavaScript, if any.
 */
 
 $(document).ready(function(){
     
    function on_click_row(eventData) {
        $(this).addClass("active");
        $(this).siblings().removeClass("active");
        $("#symbol_select").val($(this).children("#symbol").text());
    }
    
    $('#symbol_select').change(function(){
         var selectVal = $("#symbol_select option:selected").val();
         $("#sell_table > tbody > tr").each(function(){
            if ($(this).children("#symbol").text() === selectVal) {
                $(this).addClass("active");
            }
            else {
                $(this).removeClass("active");
            }
         });
    });
    
    $("#sell_table > tbody > tr").each(function(){
       $(this).click(on_click_row); 
    });
    
    $("#buy_table > tbody > tr").each(function(){
       $(this).click(on_click_row); 
    });
});