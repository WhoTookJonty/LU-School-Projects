begin transaction

--Fix Availability (EmpID), Benefits (EmpID and TypeID), BillingInfo (ContractID), Care ---(CareTypeID and ReferralID) for Foreign Key Matching

--! = Table is not dependent on another table
 
--!Doctor Table-------------------------------------------
CREATE Table Doctor
(
DocID varchar(10),
FirstName varchar(50),
PracticeName varchar(100),
Address varchar(100), 
City varchar(35), 
State char(2), 
LicenseNum varchar(12), 
LastName varchar(50)
CONSTRAINT pk_Doctor PRIMARY KEY (DocID)
)
insert into Doctor (DocID, FirstName, PracticeName, Address, City, State, LicenseNum, LastName) values ('69-0687133', 'Gabbie', 'Watson Laboratories, Inc.', '8 Colorado Center', 'Houston', 'TX', '488648561408', 'Gosse');
insert into Doctor (DocID, FirstName, PracticeName, Address, City, State, LicenseNum, LastName) values ('70-7922330', 'Jesse', 'Aton Pharma, Inc.', '8 Bobwhite Terrace', 'Santa Clara', 'CA', '829622159639', 'Petworth');
insert into Doctor (DocID, FirstName, PracticeName, Address, City, State, LicenseNum, LastName) values ('01-4765271', 'Nadiya', 'REMEDYREPACK INC.', '39326 Arizona Court', 'Austin', 'TX', '082346970810', 'Jelliman');
select * from Doctor
exec sp_help Doctor

--!Patient Table------------------------------------------
CREATE Table Patient
(
PatientID varchar(20), 
ZipCode varchar(10), 
Phone varchar(25), 
Address varchar(100), 
City varchar(35), 
State char(2), 
FirstName varchar(50), 
LastName varchar(50)
CONSTRAINT pk_Patient PRIMARY KEY (PatientID)
)
insert into Patient (PatientID, ZipCode, Phone, Address, City, State, FirstName, LastName) values ('380272876-7995802371', '88563', '915-540-1200', '8 Hintze Hill', 'El Paso', 'TX', 'Marlene', 'Cesconi');
insert into Patient (PatientID, ZipCode, Phone, Address, City, State, FirstName, LastName) values ('659397459-2406064203', '16107', '724-268-8299', '71612 Amoth Street', 'New Castle', 'PA', 'Adams', 'Lorrimer');
insert into Patient (PatientID, ZipCode, Phone, Address, City, State, FirstName, LastName) values ('482054227-8096472264', '38114', '901-559-9042', '678 Butternut Alley', 'Memphis', 'TN', 'Carissa', 'Chase');

select * from Patient
exec sp_help Patient

--!Suppliers Table-----------------------------
CREATE Table Suppliers
(
SuppliersID varchar(10),
CompanyName varchar(30), 
CONSTRAINT pk_Suppliers PRIMARY KEY (SuppliersID)
)
insert into Suppliers (SuppliersID, CompanyName) values ('13-2735780', 'Cardinal Health');
insert into Suppliers (SuppliersID, CompanyName) values ('05-9158368', 'APP Pharmaceuticals, LLC');
insert into Suppliers (SuppliersID, CompanyName) values ('98-6706641', 'Hospira, Inc.');

select * from Suppliers
exec sp_help Suppliers

--!Employees Table-----------------------------------------
CREATE Table Employees
(
EmpID varchar(10),
ZipCode char(10), 
SkillLevel int, 
Phone varchar(20), 
Address varchar(100), 
City varchar(50), 
State char(2), 
IsContractEmp bit
CONSTRAINT pk_Employees PRIMARY KEY (EmpID)
)
insert into Employees (EmpID, ZipCode, SkillLevel, Phone, Address, City, State, IsContractEmp) values ('25-0048778', '32209', 2, '904-618-8518', '192 Blackbird Way', 'Jacksonville', 'FL', 1);
insert into Employees (EmpID, ZipCode, SkillLevel, Phone, Address, City, State, IsContractEmp) values ('13-2913347', '96810', 1, '808-616-8597', '7 Chinook Street', 'Honolulu', 'HI', 0);
insert into Employees (EmpID, ZipCode, SkillLevel, Phone, Address, City, State, IsContractEmp) values ('15-4247306', '20709', 10, '301-724-1992', '14 Carioca Lane', 'Laurel', 'MD', 1);

select * from Employees
exec sp_help Employees

--!Inventory Table---------------------------
CREATE Table Inventory
(
ItemID varchar(20), 
Cost decimal, 
Item varchar(50), 
isDirect bit
CONSTRAINT pk_Inventory PRIMARY KEY (ItemID)
)
insert into Inventory (ItemID, Cost, Item, isDirect) values ('070855322-6701834493', 15.91, 'Ethyl Alcohol', 0);
insert into Inventory (ItemID, Cost, Item, isDirect) values ('446451282-0495502793', 111.48, 'Amoxicillin', 0);
insert into Inventory (ItemID, Cost, Item, isDirect) values ('782477724-9599255049', 872.78, 'HYDROQUINONE', 0);

select * from Inventory
exec sp_help Inventory
--!CareTypes Table---------------------------
CREATE Table CareTypes
(
CareTypeID varchar(3), 
CareName varchar(30)
CONSTRAINT pk_CareTypes PRIMARY KEY (CareTypeID)
)
insert into CareTypes (CareTypeID, CareName) values ('083', 'lorazepam');
insert into CareTypes (CareTypeID, CareName) values ('417', 'Ranitidine Hydrochloride');
insert into CareTypes (CareTypeID, CareName) values ('998', 'Neomycin Sulfate');

select * from CareTypes
exec sp_help CareTypes

--!PaymentType Table--------------------------------------
CREATE Table PaymentType
(
PaymentTypeID varchar(10), 
PaymentTypeName varchar(10)
CONSTRAINT pk_PaymentType PRIMARY KEY (PaymentTypeID)
)
insert into PaymentType (PaymentTypeID, PaymentTypeName) values ('1', 'Insurance');
insert into PaymentType (PaymentTypeID, PaymentTypeName) values ('2', 'Medicare');
insert into PaymentType (PaymentTypeID, PaymentTypeName) values ('3', 'Medicaid');
insert into PaymentType (PaymentTypeID, PaymentTypeName) values ('4', 'Private');

select * from PaymentType
exec sp_help PaymentType

--Referral Table-----------------------------------------
CREATE Table Referral
(
ReferralID varchar(10), 
TimesDay int, 
TimesWeek int, 
PatientID varchar(20) NOT NULL, 
DocID varchar(10) NOT NULL
CONSTRAINT pk_Referral PRIMARY KEY (ReferralID)
)
insert into Referral (ReferralID, TimesDay, TimesWeek, PatientID, DocID) values ('21-8685224', 7, 1, '380272876-7995802371', '69-0687133');
insert into Referral (ReferralID, TimesDay, TimesWeek, PatientID, DocID) values ('06-7421131', 4, 3, '659397459-2406064203', '70-7922330');
insert into Referral (ReferralID, TimesDay, TimesWeek, PatientID, DocID) values ('87-9748697', 6, 7, '482054227-8096472264', '01-4765271');

select * from Referral


--!Contracts Table----------------------------------------
CREATE Table Contracts
(
ContractID varchar(10), 
ReferralID varchar(10), 
StartDate date, 
EndDate date, 
DurationDays int, 
RatePerVisit decimal
CONSTRAINT pk_contracts PRIMARY KEY (ContractID)
)
insert into Contracts (ContractID, ReferralID, StartDate, EndDate, DurationDays, RatePerVisit) values ('97-3369157', '21-8685224', '10/22/2020', '07/27/2021', 24, 4367.33);
insert into Contracts (ContractID, ReferralID, StartDate, EndDate, DurationDays, RatePerVisit) values ('84-1960601', '06-7421131', '04/29/2021', '05/19/2021', 87, 1387.88);
insert into Contracts (ContractID, ReferralID, StartDate, EndDate, DurationDays, RatePerVisit) values ('73-9033053', '87-9748697', '12/13/2020', '11/19/2020', 69, 8436.67);


--!EmpType Table--------------------------
CREATE Table EmpType 
(
TypeID char(2), 
TypeName varchar(30), 
Salary int
CONSTRAINT pk_EmpType PRIMARY KEY (TypeID)
)
insert into EmpType (TypeID, TypeName, Salary) values ('43', 'Executive Secretary', 68.9);
insert into EmpType (TypeID, TypeName, Salary) values ('53', 'Help Desk Operator', 80.62);
insert into EmpType (TypeID, TypeName, Salary) values ('72', 'Electrical Engineer', 23.7);
--Benefits Table-------------------------
CREATE Table Benefits
(
EmpID varchar(10), 
TypeID char(2),
GrossPay decimal, 
FICAWitholdings decimal, 
InsDeduct decimal, 
KContribution decimal, 
CONSTRAINT pk_Benefits PRIMARY KEY (EmpID, TypeID),
CONSTRAINT fk_benefits_EmpEmpType FOREIGN KEY (EmpID, TypeID) references EmpEmpType
)
insert into Benefits (GrossPay, FICAWitholdings, InsDeduct, KContribution, EmpID, TypeID) values (60316.31, 5733.4, 5951.92, 8562.34, '25-0048778', '43');
insert into Benefits (GrossPay, FICAWitholdings, InsDeduct, KContribution, EmpID, TypeID) values (95145.49, 6346.24, 989.42, 6255.81, '13-2913347', '53');
insert into Benefits (GrossPay, FICAWitholdings, InsDeduct, KContribution, EmpID, TypeID) values (80620.03, 2955.34, 9001.33, 8280.25, '15-4247306', '72');


--!SkillType Table-----------------------
CREATE Table SkillType
(
SkillTypeID char(2), 
SkillName varchar(30)
CONSTRAINT pk_SkillType PRIMARY KEY (SkillTypeID)
)
insert into SkillType (SkillTypeID, SkillName) values ('59', 'Research Assistant III');
insert into SkillType (SkillTypeID, SkillName) values ('84', 'Payment Adjustment Coordinator');
insert into SkillType (SkillTypeID, SkillName) values ('98', 'Speech Pathologist');
--!InsCompanies------------------------
CREATE Table InsCompanies
(
InsId char(3), 
InsName varchar(50)
CONSTRAINT pk_InsCompanies PRIMARY KEY (InsID)
)
insert into InsCompanies (InsID, InsName) values ('597', 'TYA Pharmaceuticals');
insert into InsCompanies (InsID, InsName) values ('859', 'McKesson');
insert into InsCompanies (InsID, InsName) values ('675', 'Contract Pharmacy Services-PA');

--!CostReport Table---------------------
CREATE Table CostReport
(
CostReportId char(3), 
Date smalldatetime
CONSTRAINT pk_CostReport PRIMARY KEY (CostReportID)
)
insert into CostReport (CostReportID, Date) values ('250', '08/09/2021 12:00:00');
insert into CostReport (CostReportID, Date) values ('378', '10/05/2021 12:00:00');
insert into CostReport (CostReportID, Date) values ('935', '11/22/2020 12:00:00');

--Ensure date is formatted correctly






--Care Table------------------------------------
CREATE Table Care
(
CareTypeID varchar(3), 
ReferralID varchar(10)
CONSTRAINT pk_Care PRIMARY KEY (CareTypeID, ReferralID),
CONSTRAINT fk_Care_CareTypes FOREIGN KEY (CareTypeID) references CareTypes,
CONSTRAINT fk_Care_Referral FOREIGN KEY (ReferralID) references Referral
);
insert into Care (CareTypeID, ReferralID) values ('083', '21-8685224');
insert into Care (CareTypeID, ReferralID) values ('417', '06-7421131');
insert into Care (CareTypeID, ReferralID) values ('998', '87-9748697');


--Payments Table----------------------------------------
CREATE Table Payments
(
PaymentTypeID varchar(10), 
ContractID varchar(10)
CONSTRAINT pk_Payments PRIMARY KEY (PaymentTypeID, ContractID),
CONSTRAINT fk_Payments_PaymentType FOREIGN KEY (PaymentTypeID) references PaymentType,
CONSTRAINT fk_Payments_Contracts FOREIGN KEY (ContractID) references Contracts
)
insert into Payments (PaymentTypeID, ContractID) values ('1', '97-3369157');
insert into Payments (PaymentTypeID, ContractID) values ('2', '84-1960601');
insert into Payments (PaymentTypeID, ContractID) values ('3', '73-9033053');

--BillingInfo-------------------------------------------
CREATE Table BillingInfo
(
BillingInfoID varchar(10), 
Duration decimal, 
Date date, 
ContractID varchar(10) NOT NULL,
PatientID varchar(20) NOT NULL
CONSTRAINT pk_BillingInfo PRIMARY KEY (BillingInfoID),
CONSTRAINT fk_BillingInfo_Contracts FOREIGN KEY (ContractID) references Contracts,
CONSTRAINT fk_BillingInfo_Patient FOREIGN KEY (PatientID) references Patient
)
insert into BillingInfo (BillingInfoID, Duration, Date, ContractID, PatientID) values ('83-2118628', 14.59, '03/30/2021', '97-3369157', '380272876-7995802371');
insert into BillingInfo (BillingInfoID, Duration, Date, ContractID, PatientID) values ('73-4332582', 18.95, '12/15/2020', '84-1960601', '659397459-2406064203');
insert into BillingInfo (BillingInfoID, Duration, Date, ContractID, PatientID) values ('82-8690013', 2.74, '02/15/2021', '73-9033053', '482054227-8096472264');

--PaymentBill Table-------------------------------------
CREATE Table PaymentBill
(
BillingInfoID varchar(10), 
PaymentTypeID varchar(10)
CONSTRAINT pk_PaymentBill PRIMARY KEY (BillingInfoID, PaymentTypeID),
CONSTRAINT fk_PaymentBill_BillingInfo FOREIGN KEY (BillingInfoID) references BillingInfo,
CONSTRAINT fk_PaymentBill_PaymentType FOREIGN KEY (PaymentTypeID) references PaymentType
)
insert into PaymentBill (BillingInfoID, PaymentTypeID) values ('83-2118628', '1');
insert into PaymentBill (BillingInfoID, PaymentTypeID) values ('73-4332582', '2');
insert into PaymentBill (BillingInfoID, PaymentTypeID) values ('82-8690013', '3');

--Scheduling Table--------------------------
CREATE Table Scheduling
(
SchedID varchar(10), 
StartDateTime smalldatetime, 
EndDateTime smalldatetime, 
ContractID varchar(10) NOT NULL, 
EmpID varchar(10) NOT NULL
CONSTRAINT pk_Scheduling PRIMARY KEY (SchedID),
CONSTRAINT fk_Scheduling_Employees FOREIGN KEY (EmpID) references Employees,
CONSTRAINT fk_Scheduling_Contracts FOREIGN KEY (ContractID) references Contracts
)
insert into Scheduling (SchedID, StartDateTime, EndDateTime, ContractID, EmpID) values ('83-0108872', '10/25/2020 12:00:00', '08/21/2021 1:00:00', '97-3369157', '25-0048778');
insert into Scheduling (SchedID, StartDateTime, EndDateTime, ContractID, EmpID) values ('54-8379115', '02/17/2021 12:00:00', '07/14/2021 1:00:00', '84-1960601', '13-2913347');
insert into Scheduling (SchedID, StartDateTime, EndDateTime, ContractID, EmpID) values ('42-5583871', '02/20/2021 12:00:00', '03/31/2021 1:00:00', '73-9033053', '15-4247306');

--SupplyItem Table--------------------------------
CREATE Table SupplyItem
(
ItemID varchar(20), 
SuppliersID varchar(10), 
DateReceived date
CONSTRAINT pk_SupplyItem PRIMARY KEY (ItemID, SuppliersID),
CONSTRAINT fk_SupplyItem_Inventory FOREIGN KEY (ItemID) references Inventory,
CONSTRAINT fk_SupplyItem_Suppliers FOREIGN KEY (SuppliersID) references Suppliers
)
insert into SupplyItem (ItemID, SuppliersID, DateReceived) values ('070855322-6701834493', '13-2735780', '01/04/2021');
insert into SupplyItem (ItemID, SuppliersID, DateReceived) values ('446451282-0495502793', '05-9158368', '06/26/2021');
insert into SupplyItem (ItemID, SuppliersID, DateReceived) values ('782477724-9599255049', '98-6706641', '04/02/2021');

--InvRef Table-----------------------------
CREATE Table InvRef
(
ItemID varchar(20), 
ReferralID varchar(10)
CONSTRAINT pk_InvRef PRIMARY KEY (ItemID, ReferralID),
CONSTRAINT fk_InvRef_Inventory FOREIGN KEY (ItemID) references Inventory,
CONSTRAINT fk_InvRef_Referral FOREIGN KEY (ReferralID) references Referral
)
insert into InvRef (ItemID, ReferralID) values ('070855322-6701834493', '21-8685224');
insert into InvRef (ItemID, ReferralID) values ('446451282-0495502793', '06-7421131');
insert into InvRef (ItemID, ReferralID) values ('782477724-9599255049', '87-9748697');

--InvBillingInfo Table---------------------
CREATE Table InvBillingInfo
(
ItemID varchar(20), 
BillingInfoID varchar(10), 
Qnty int
CONSTRAINT pk_InvBillingInfo PRIMARY KEY (ItemId, BillingInfoID),
CONSTRAINT fk_InvBillingInfo_Inventory FOREIGN KEY (ItemID) references Inventory, 
CONSTRAINT fk_InvBillingInfo_BillingInfo FOREIGN KEY (BillingInfoID) references BillingInfo
)
insert into InvBillingInfo (ItemID, BillingInfoID, Qnty) values ('070855322-6701834493', '83-2118628', 2348);
insert into InvBillingInfo (ItemID, BillingInfoID, Qnty) values ('446451282-0495502793', '73-4332582', 5507);
insert into InvBillingInfo (ItemID, BillingInfoID, Qnty) values ('782477724-9599255049', '82-8690013', 5548);

--EmpEmpType Table------------------------
CREATE Table EmpEmpType
(
EmpID varchar(10), 
TypeID char(2)
CONSTRAINT pk_EmpEmpType PRIMARY KEY (EmpID, TypeID),
CONSTRAINT fk_EmpEmpType_Employees FOREIGN KEY (EmpID) references Employees,
CONSTRAINT fk_EmpEmpType_EmpType FOREIGN KEY (TypeID) references EmpType
)
insert into EmpEmpType (EmpID, TypeID) values ('25-0048778', '43');
insert into EmpEmpType (EmpID, TypeID) values ('13-2913347', '53');
insert into EmpEmpType (EmpID, TypeID) values ('15-4247306', '72');


--EmpSkill Table---------------------------
CREATE Table EmpSkill
(
SkillTypeID char(2), 
EmpID varchar(10)
CONSTRAINT pk_EmpSkill PRIMARY KEY (SkillTypeID, EmpID),
CONSTRAINT fk_EmpSkill_SkillType FOREIGN KEY (SkillTypeID) references SkillType,
CONSTRAINT fk_EmpSKill_Employees FOREIGN KEY (EmpID) references Employees
)
insert into EmpSkill (SkillTypeID, EmpID) values ('59', '25-0048778');
insert into EmpSkill (SkillTypeID, EmpID) values ('84', '13-2913347');
insert into EmpSkill (SkillTypeID, EmpID) values ('98', '15-4247306');

--Availability Table----------------------
CREATE Table Availability
(
AvailabilityID varchar(10), 
StartTime time, 
EndTime time, 
Date date, 
EmpID varchar(10) NOT NULL
CONSTRAINT pk_Availability PRIMARY KEY (AvailabilityID),
CONSTRAINT fk_Availability FOREIGN KEY (EmpID) references Employees,

)
insert into Availability (AvailabilityID, StartTime, EndTime, Date, EmpID) values ('25-0048778', '6:40:05.000', '17:37:17.000', '08/12/2021', '37-6181199');
insert into Availability (AvailabilityID, StartTime, EndTime, Date, EmpID) values ('13-2913347', '3:08:19.000', '14:39:39.000', '06/18/2021', '39-4049056');
insert into Availability (AvailabilityID, StartTime, EndTime, Date, EmpID) values ('15-4247306', '12:00:28.000', '23:22:33.000', '03/18/2021', '30-4661644');

--Insurance Table------------------------
CREATE Table Insurance
(
InsID char(3), 
ContractID varchar(10), 
RatePerVisit decimal, 
MaxNumVisits int, 
DurationDays int, 
SkillLevelReq int
CONSTRAINT pk_Insurance PRIMARY KEY (InsID, ContractID),
CONSTRAINT fk_Insurance_InsCompanies FOREIGN KEY (InsID) references InsCompanies,
CONSTRAINT fk_Insurance_Contracts FOREIGN KEY (ContractID) references Contracts
)
insert into Insurance (InsID, ContractID, RatePerVisit, MaxNumVisits, DurationDays, SkillLevelReq) values ('597', '97-3369157', 475.54, 73, 675, 3);
insert into Insurance (InsID, ContractID, RatePerVisit, MaxNumVisits, DurationDays, SkillLevelReq) values ('859', '84-1960601', 237.01, 30, 891, 1);
insert into Insurance (InsID, ContractID, RatePerVisit, MaxNumVisits, DurationDays, SkillLevelReq) values ('675', '73-9033053', 430.65, 47, 371, 8);

--SchedDetails Table--------------------
CREATE Table SchedDetails
(
SchedDetailID varchar(20), 
SchedID varchar(10), 
CareTypeID varchar(3), 
ItemID varchar(20), 
Qty int
CONSTRAINT pk_SchedDetails PRIMARY KEY (SchedDetailID, SchedID, CareTypeID, ItemID),
CONSTRAINT fk_SchedDetails_Scheduling FOREIGN KEY (SchedID) references Scheduling,
CONSTRAINT fk_SchedDetails_CareTypes FOREIGN KEY (CareTypeID) references CareTypes,
CONSTRAINT fk_SchedDetails_Inventory FOREIGN KEY (ItemID) references Inventory
)
insert into SchedDetails (SchedDetailID, SchedID, CareTypeID, ItemID, Qty) values ('718630686-1464759960', '83-0108872', '083', '070855322-6701834493', 48006);
insert into SchedDetails (SchedDetailID, SchedID, CareTypeID, ItemID, Qty) values ('136267842-7516541828', '54-8379115', '417', '446451282-0495502793', 4989);
insert into SchedDetails (SchedDetailID, SchedID, CareTypeID, ItemID, Qty) values ('148665881-7719896889', '42-5583871', '998', '782477724-9599255049', 33335);

--DirectCosts Table---------------------
CREATE Table DirectCosts
(
DirectCostID char(3), 
CostReportID char(3), 
Labor decimal, 
InvCost decimal
CONSTRAINT pk_DirectCosts PRIMARY KEY (DirectCostID, CostReportID),
CONSTRAINT fk_DirectCosts_CostReport FOREIGN KEY (CostReportID) references CostReport
)
insert into DirectCosts (DirectCostID, CostReportID, Labor, InvCost) values ('000', '250', 677545.03, 35210.81);
insert into DirectCosts (DirectCostID, CostReportID, Labor, InvCost) values ('001', '378', 21569.18, 680293.13);
insert into DirectCosts (DirectCostID, CostReportID, Labor, InvCost) values ('002', '935', 825249.01, 277680.89);

--IndirectCosts Table-------------------
CREATE Table IndirectCosts
(
IndirectCostID char(3), 
CostReportId char(3), 
StaffSalaries decimal, 
Rent decimal, 
Utilities decimal, 
Equipment decimal
CONSTRAINT pk_IndirectCosts PRIMARY KEY (IndirectCostID, CostReportID),
CONSTRAINT fk_IndirectCosts_CostReport FOREIGN KEY (CostReportID) references CostReport
) 
insert into IndirectCosts (IndirectCostID, CostReportID, StaffSalaries, Rent, Utilities, Equipment) values ('000', '250', 21493.1, 321584.49, 9291.3, 785.03);
insert into IndirectCosts (IndirectCostID, CostReportID, StaffSalaries, Rent, Utilities, Equipment) values ('001', '378', 99651.71, 70968.15, 1996.79, 5426.19);
insert into IndirectCosts (IndirectCostID, CostReportID, StaffSalaries, Rent, Utilities, Equipment) values ('002', '935', 33791.45, 176507.93, 8955.91, 1325.96);

commit transaction
rollback transaction

