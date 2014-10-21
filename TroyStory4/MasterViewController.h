//
//  MasterViewController.h
//  TroyStory4
//
//  Created by S on 10/21/14.
//  Copyright (c) 2014 Ryan Siska. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface MasterViewController : UITableViewController <NSFetchedResultsControllerDelegate>

@property (strong, nonatomic) NSManagedObjectContext *managedObjectContext;


@end

/*
 
 - when setting it up, we used the Master Detail Application template and made sure that Core Data was checked - using the Master Detail Application ensures that we get that managedObjectContext property that we can use on self

step 1 
 - we just set up the project to be able to use Core Data and recreate how Core Data is used - one important thing was to check the Core Data box when we were setting up the program
 - we also deleted one @property from this .h file and deleted everything from MasterVC, adding back the #import, interface, and implemenation - nothing added yet

 step 2
 - we put a text field in the navigation bar - important thing here was that we changed the title of the navigation by opening up the right side panel and changing "prompt"
 - we then created an IBAction for the text field - important thing here was that instead of creating a delegate for it, we just hooked up the "did end on exit" from the right side column to the IBAction - from what Max said, this can also be used to switch from one text fielx to anoterh

 step 3
 - normal processes - we created the trojans array and added the <UITableViewDataSource> - we then added the cellForRow... and numberOfRows... - the only new thing we did here related to Core Data was to add the ManagedObject which gives back an object from the trojans array at a specific index - we haven't gone too much into this yet

step 4
 - start to where we're using the Core Data - opened the TroyStory4.xcdatamodeld folder and added a new entity of Trojan - don't make plural because it implies that they're all plural - then we added the viewDidLoad and loadData - the parts within loadData are pulling the data from that Trojan thing we set in Core Data and then set that to the array that we created above, then we reloaded the data of the tableview so it shows up
 - also had to reset the simulator via iOS Simulator - Reset Content and Settings or get an error
 
 step 5
 - add the data pieces within the onTrojanConquest - this adds a Trojan object that we created in the .xcdata... with whatever name was in the text field - we then save to the managedObjectContext and call the loadData to reload the tableView data with the new name
 
 step 6
 - we went into the cxdatamodel again and added a new attribute of "prowess" to the Trojan - set as an integer 32 or something - he said this is the standard - then we added that to the onTrojanConquest so that the trojans will get a random prowess number assigned to them - we had to add the plus 1 because it starts at 0
 - then we went down to the cellForRow... and added the detailedTextLabel part to show the prowess and used that stringValue at the end to convert it to text
- we also had to change in storyboard to show the detailTextLabel - a simple change in the panel opened on the right side
*/