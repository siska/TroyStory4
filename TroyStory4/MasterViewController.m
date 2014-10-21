#import "MasterViewController.h"

@interface MasterViewController() <UITableViewDataSource>
@property NSArray *trojans; //step 3

@end

@implementation MasterViewController

-(IBAction)onTrojanConquest:(UITextField *)sender
{ //step 5 - everything down to the resignFirstResponder
    NSManagedObject *trojan = [NSEntityDescription insertNewObjectForEntityForName:@"Trojan" inManagedObjectContext:self.managedObjectContext];

    [trojan setValue:sender.text forKey:@"name"];
    [trojan setValue:@(arc4random_uniform(10)+1) forKey:@"prowess"]; //step 6
    [self.managedObjectContext save:nil]; //the save is the error state - don't set to nil in an actual app
    [self loadData];

    sender.text = @"";
    [sender resignFirstResponder];
}

-(void)viewDidLoad //step 4
{
    [self loadData];
}

-(void)loadData //step 4
{
    NSFetchRequest *request = [[NSFetchRequest alloc] initWithEntityName:@"Trojan"];
    NSSortDescriptor *sortDescriptor1 = [[NSSortDescriptor alloc] initWithKey:@"name" ascending:YES]; //step 7
    NSSortDescriptor *sortDescriptor2 = [[NSSortDescriptor alloc] initWithKey:@"prowess" ascending:NO];// step 7

    request.sortDescriptors = [NSArray arrayWithObjects:sortDescriptor1, sortDescriptor2, nil]; //step 7
    self.trojans = [self.managedObjectContext executeFetchRequest:request error:nil]; //step 4 - don't use nil here in actual apps, do something with the error NSError(error) etc.
    [self.tableView reloadData];
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    NSManagedObject *trojan = [self.trojans objectAtIndex:indexPath.row];

    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"Cell"];
    cell.textLabel.text = [trojan valueForKey:@"name"];
    cell.detailTextLabel.text = [[trojan valueForKey:@"prowess"] stringValue]; //step 6
    return cell;
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.trojans.count;
}

@end