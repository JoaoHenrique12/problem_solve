# Patterns for api design
pg. 85

## Api Fundamentals

How do api designs differ

- One general versus many specific/specialized endpoints;
- fine versus coarse-grained endpoint and operation scope;
- Few operations carrying much data back and forth versus many chatty interactions carrying little data;
- Data currentness versus correctness;
- stable contracts versus fast changing ones;

Architecturally significant requirements

- Quality goals: developmental, operational, managerial;
- understandability: structure of the representation elements in request and response messages;
- information sharing versus hidding: how the implementation can change without affecting clients later on;
- amount of coupling: ;
- modifiability: ;
- performance and scalability: marshalling and unmarshalling of the payload;
- data parsimony: add new data to api is easier than remove it;
- security and privacy: ;

DX = Developer Experience
UX = Developer Experience
DX = function, stability, ease of use, clarity.

Domain Model for Remote APIs

- communication participants;
- endpoints offer contracts describing operations;
- messages as conversation building blocks: request/reply, one-way exchange, event notification, request-multiple replies;
- api contract;


- Quality goals: 
  - developmental: easy to discover, learn and understand;
  - operational: performance, reliability, security requirements;
  - managerial: evolvable, maintainable;

## Lakeside Mutual Case Study

- DDD; context map ;MDSL (microservice Domains-Specific Language);
- github: https://github.com/Microservice-API-Patterns/LakesideMutual;


## API Decision Narratives

Prelude: patterns as decision options, forces as decision criteria

```
# why-statement

In the context of [feature or component],
wanting to/facing the need for [requirement or quality goal],
we decided to [option chosen]
and neglected [alternatives]
to achieve [benefit],
accepting that [negative consequences].
```

- [decision making](https://ozimmer.ch/practices/2020/04/27/ArchitectureDecisionMaking.html)
  - good and bad justificatives for an achitecture decision;
  - [markdown decision making](https://github.com/adr/madr?tab=readme-ov-file);

Foundational API Decisions and Patterns
- Where should the API be accessible from, or how visible is the API?
- Which integration types should be supported by the API?
- Should the API be documented? If so, how should it be documented?


### Visibility:

...As a consequence, the performance and scalability requirements
for the two kinds of API visibility can be very different.

More visible APIs might have higher security demands than less visible ones...

Sample decision outcome. How did the case study team at Lakeside Mutual decide, and why?
In the context of the customer self-service channel, facing the need to serve external
users such as existing customers, the API designers at Lakeside Mutual decided to evolve
their SOLUTION-INTERNAL API into a COMMUNITY API, neglecting PUBLIC API,
to be able to address the wants and needs of a known user population and predict
the API workload, accepting that unregistered users (prospective customers)
cannot be served by this API.

### API Integration Types

Decision: Integration types supported by the API
Do the API clients display forms and processing results to end users, for instance,
in mobile apps, Web applications, and rich client applications? Or should they
serve as wrappers and adapters in mid-tiers and backend tiers that host applica-
tion components?

### Documentation of the API

Decision: Documentation of the API
Should the API be documented? If so, how should it be documented?

...For example, OpenAPI Specification
(formerly known as Swagger), API Blueprint, Web Application
Description Language (WADL), and Web Services Description Language (WSDL)

Sample decision outcome. Lakeside Mutual decided to apply the pattern:
In the context of the customer self-service channel,
wanting to improve the client developer experience,
the Lakeside Mutual API designers chose elaborate API and the
contract languages MDSL and OpenAPI,
to achieve an interoperable API that is easy to learn and use,
accepting that its documentation has to be kept current as the API evolves.

## Decisions about API Roles and Responsibilities

- Which architectural role should an API endpoint play?
- What is the responsibility of each API operation?

Operations can solely compute results, only read state, create new state without
reading it, or realize a state transition. 

For example, if only stateless computations and data reading are performed on an endpoint,
their results can be cached and the corresponding implementation can be replicated to scale
out more easily.

## Architectural Role of an Endpoint

API designers have to address semantic concerns and find an appropriate business granularity
for the services exposed by the API. 

Decision: Architectural role of an endpoint Which technical role should an API endpoint play
in the architecture?

For instance, API designers have to consider contract expressiveness
and service granularity: simple interactions give the client good control and make
processing efficient, but action-oriented capabilities can promote qualities such as
consistency, compatibility, and evolvability.

If not done well, the chosen endpoint-operation layout can have a
negative impact on response time and lead to chatty APIs.

Highly data-centric approaches tend to lead to create, read, update,
delete (CRUD) APIs, which can negatively affect coupling. 

## Refining information Holder Roles

Figure 3.7 Responsibility category: information resource holder types

Information Holder Resource:
- Operational Data Holder;
- Mater data Holder;
- Reference Data Holder;
- Data Transfer Resource;
- Link Lookup Resource;

Use of the words create, read, update, and delete in the
preceding pattern sketches should not indicate that such designs are the intended
or only possible solution for realizing the patterns. Such designs quickly lead to
chatty APIs with bad performance and scalability properties.
They can also lead to unwanted coupling and complexity.

anemic domain model [Fowler 2003];

- Operational data covers the events in the transactions of an organization.
For example, making an order to a business, shipping items to a customer, or
hiring employees are all examples of business transactions that would form
operational data;
- Master data is essential information that supports the business transactions
realized in a system. Typically, it covers the digital representation of the par-
ties of an organization such as persons, customers, employees, or suppliers. It
also covers the main things relevant to an organization, such as the products,
materials, items, and vehicles. Finally, master data may represent physical or
virtual places, such as locations or sites. Master data is usually long-living and
frequently referenced;
- Reference data is inert data referenced and shared in one or more systems
and among the microservices and components making up these systems.
Examples are country codes, zip codes, and delivery status codes (such as
pending, information received, in transit, out on delivery, failed attempt,
delivered). Reference data is long-living, simple, and cannot be changed by
clients directly.

- Reference Data Holder. Caching of this data is possible, which leads to high performance. If caching is
used, consistency versus performance trade-offs might have to be made. 

- Link Lookup Resource: Links can also help to reduce message sizes by placing a link in
the message instead of the content, as in the Embedded Entity pattern. But if clients need all
or part of the information, this practice increases the required number of calls. Both placing
links in messages and including content in an Embedded Entity influence the overall resource use.

- Data Transfer Resource is an endpoint role pattern representing a resource whose primary function
is to offer a shared data exchange between clients.

in master data holder: Treat delete operations as special forms of updates;

In frequent cases, domain Entities can also be considered to supply endpoint candidates. For a deeper discussion
on the relation of APIs and DDD, see [Singjai 2021a, 2021b, 2021c]. 

## Defining Operation Responsibilities

Decision: Operation responsibility
What are the read-write characteristics of each API operation ?

Responsibility of an API Operation:
  - Computation Function: only compute a result and not read or write;
  - State Creation Operation: only creates states on an API endpoint (write-only);
  - Retrieval Operation: only finds and delivers data without allowing clients to change it (read-only);
  - State Transition Operation: performs one or more activities causing a server-side state change;

### State Creation Operation

Their impact on coupling should be considered. Because the provider state is not read,
it can become difficult to ensure consistency. As incidents that clients report happen
before they arrive at the provider, timing needs to be considered in the design as well.
Finally, reliability is an important concern, as messages might appear in a different order
or be duplicated at the API provider.

### Retrieval Operation

In addition, workload management considerations should be made, especially if sig-
nificant data volumes are transferred. Also, more information transferred from client
to API provider (and back) can lead to higher coupling and larger message sizes.

to request a result report that contains a machine-readable representation of the requested
information. Add search, filter, and formatting capabilities to the operation signature.

### State Transition Operation

Examples of such operations are full and partial updates to server-side data as well as
deletions of such data.

For longer-running process instances, it can be difficult to keep the client-side state
and the states of provider-side backends consistent. In addition, it is important to
consider whether there are dependencies on state changes made earlier in the process.

### Computation Function

- is an operation that computes a result solely from the client input and does not read or
write server-side state;
- In many cases require reproducibility of executions;


## Selecting Message Representation Patterns

- What is the optimal number of API message parameters and body parts and an
adequate structure of these representation elements ?
-  What are the meaning and stereotypes of the representation elements ?

Decisions for this category likely have to be made whenever a message is designed
or refactored. The representation elements transported in the message, including
request parameters and body elements, are considerations in these decisions.

Figure 3.9, this category contains four typical decisions. The first
is on the structure of the parameter representation. Based on this representation, it
can be decided what the meaning and responsibility of message elements are. Next,
it can also be decided whether multiple data elements require additional informa-
tion. Finally, the whole message can or cannot be extended with context information.

## Flat versus Nested Structure of Representation Elements

Decision: Structure of parameter representation

What is the adequate overall representation structure for the data elements to be
transmitted in the message?


Structure of parameter representation
- atomic parameter: scalar representation;
- atomic parameter list: list representation;
- parameter tree: complex representation with one root element;
- parameter forest: complex representation with multiple root elements;

Decisions on the number of messages and on each message structure require a careful
analysis of when which data element is required. Sometimes this cannot be deduced
analytically, and extensive testing is required to optimize the message structures.

All kinds of additional data to be transmitted with the message, such as security-
related data (for example, security tokens) or other metadata (for example, message
and correlation identifiers or error codes), have to be considered here as well. 

Sometimes, a number of data elements can be grouped and sent in one message,
again to improve resource use and performance. For instance, if an edge node of a
cloud-based IoT solution collects data from sensors (such as a set of measurements
in a certain time interval), it often makes sense to send this data to the cloud core in
batches rather than sending each data element separately. 

Optimizing resource use and performance may have a negative influence on other
qualities, such as understandability, simplicity, and complexity. For instance, an API
that offers one message per specific task to be performed on an employee record
would contain many more operations in the API endpoint than an alternative design
that just allows for transmitting a specified set of employee records in their entirety.
The former option might have a better resource utilization and performance, but the
API design is also much more complex and thus harder to understand.

For instance, structures that are easy to create and populate might be
difficult to understand or debug, whereas a compact format that is light in transfer
might be difficult to document, understand, and parse.

About security issues: in some cases, such considerations might
even lead to a different message structure or API refactoring (for instance, splitting
endpoints or operations Stocker 2021b). 

## Element Stereotypes

DTR: Data Transfer Representations

Decision: Element stereotypes
What do the individual representation elements mean? Which purposes within
the DTRs do they have?

Meaning of stereotypes of message elements
- Data eleement: a structured data-only element;
- ID Eelement: an element containing a id;
- Link Element: an element containing a semantically typed hyperlink;
- Metadata Element: an element containing metadata annotating other elements;


## Governing API Quality

Endpoint-specific qualities
- Explicit specification of quality objectives and penalties;
- Metering and charging for api consumption;
- Preventing API Clients from excessive usage;
- Communication of errors;
- Explicit context representation;

Quality
- handling of referenced data (decide for some instances of)
  - message
- avoid unnecessary data transfer (decide for some instances of)
  - operation

## Identification and Authentication of the API Client

In summary, client identification and authentication are the foundations for
achieving certain security qualities and support many techniques to establish QoS
and cost control.

Client identification and authentication:
- do nothing;
- api-key;
- api-key combined with secret key;
- authorization protocol;
- authentication protocol;

Commented topics:
- Oauth2.0
- OpenID Connect
- Kerberos
- LDAP

API Keys help to establish basic security. Although they
require following a registration process, API Keys bring only a slight degradation in
terms of ease of use for clients once they have been obtained (compared to no secure
identification and authentication). The other options are less easy to use, as they
require dealing with more complex protocols and setting up the required services
and infrastructure. The management of user account credentials required in authen-
tication and authorization protocols can be tedious both on the client and provider
side; this is avoided in all options using API Keys, including its combination with a
secret key.

## Metering and Charging for API Consumption


Problem: How can the API provider meter API service consumption and charge for it?

Solution: Assign a Pricing Plan for the API usage to the API Description that is used
to bill API customers, advertisers, or other stakeholders accordingly. Define
and monitor metrics for measuring API usage, such as API usage statistics per
operation.

Metering and Charging for API Consumption:
- Consider if not decided yet about Client identification and Authentication
- Do nothing
- Pricing Plan:
  - Rate Limit
  - Authentication


Pricing Plan:
- Freemium Model
- Market-based Pricing
- Usage-based Pricing
- Flat-Rate Subscription

Preventing API Clients from Excessive API Usage:

Problem: How can the API provider prevent API clients from excessive API usage?
Solution: Introduce and enforce a Rate Limit to safeguard against API clients that overuse
the API.

For example, if all clients are in-house clients or trusted partners, the overhead of a
Rate Limit might not be justified.

Preventing API Clients From Excessive Usage:
- Consider if not decided yet about Client identification and Authentication
- Do Nothing
- Rate Limit
  - Can use Authentication


Introducing Rate Limits produces costs and can be perceived negatively by clients.
Thus, it has to be judged whether the risks of API abuse imposed by a few clients
are higher than the risks and costs associated with introducing Rate Limits for
all clients.

Service Layer Agreement (SLA)

## Communication of Errors

However, rather elaborate error messages can reveal information that
is problematic with regard to security, as disclosing more information
about system internals opens up attack vectors.

Communication of Errors:
- Do Nothing
- Error Reporting
- Protocol-level error codes

## Explicit Context Representation

Exchange of Context Information Required:
- Context Representation
- Do Nothing

## Deciding For API Quality Improvements

However, a combination of two or even three of the patterns increases the
complexity of the API design and programming substantially for rather little
gains, as all four patterns influence a similar set of desired qualities positively.

Avoid Unnecessary Data Transfer:
- Do nothing
- Wish List
- Wish Template
- Conditional Request
- Request Bundle


### Pagination Decision

Subset of High Number of Data Records with the Same Structure Required
- Parameter Tree
- Parameter Forest
- Do nothing
- Pagination
  - Page-Based Pagination
  - Cursor-Based Pagination
  - Offset-Based Pagination: 
  - Time-Based Pagination

Pagination can be used for:
- Parameter Tree
- Parameter Forest
- Atomic Parameter List

Pagination Methods:
- Offset-based Pagination: Compared to simple pages, an offset specified by
the API client enables more flexibility in controlling the number of requested
results or changes in the page size.
- Cursor-Based Pagination: This variant does not rely on the index of an element
but instead on a cursor that the API client can control.
- Time-Based Pagination: This variant is similar to Cursor-Based Pagination but
uses timestamps instead of cursors to request chunks!!!

From a security standpoint, retrieving and encoding large data sets can incur
high effort and cost on the provider side and can thus open up an attack vector for a
denial-of-service attack.

#### Postgresql Implementations

The first thing at mind may be the following:

```sql
BEGIN;

DECLARE my_search_cursor CURSOR FOR 
SELECT * FROM large_table ORDER BY id;

FETCH 10 FROM my_search_cursor;

FETCH 10 FROM my_search_cursor;

CLOSE my_search_cursor;
COMMIT;
```

However, implement it require a stateful connection,
wich is impratical for apis and basic web pages.

The second option is use limit + offset.

```sql
SELECT * FROM your_table_name
ORDER BY id ASC  -- Or any unique column
LIMIT 10 
OFFSET 20;
```

Wich is simple, and very easy to use. However, the offset is calculated by
reading the lines skiped, therefore it may cause issues on large sets PostgreSQL
still has to "read" through the skipped rows even though it doesn't show them to you.

For massive datasets, "Keyset Pagination" (using WHERE id > last_seen_id)
is often faster. However the api caller must inform the last_seen_id, which may be
a bad thing for users.

### Other Means of Avoiding Unnecessary Data Transfer

#### Wish List

This may be implemented using pydantic + model_dump and filter fields to show only desired ones.

- Wish List: A possible way to solve this problem is to let the client inform the provider
at runtime about its data fetching preferences. A simple option to do this is to let the client
send a list of its desires.
- Wish Template: An alternative solution that works better for complex parameters is to let the
client send a template (or mock object) expressing the wishes as examples in its request.

## Handling Referenced Data in Messages

Not every Data Element in a message can be represented as a plain data record, as
some data records contain references to other data records. An important question is
how these local data references should be reflected in the API; answers to it determine
the API granularity and its coupling characteristics.

Data Element -> Handlig of Referenced Data
- Embedded Entity
- Linked Information Holder
  - Link Lookup Resource
  - Link Element

Embedded Entity:

Problem: How can one avoid sending multiple messages when their receivers require
insights about multiple related information elements?

Solution: For any data relationship that the client wants to follow, embed a Data Element
in the request or response message that contains the data of the target end of the
relationship. Place this Embedded Entity inside the representation of the source
of the relationship.

Linked Information Holder:

Problem: How can messages be kept small even when an API deals with multiple
information elements that reference each other?

Solution: Add a Link Element to messages that pertain to multiple related information
elements. Let this Link Element reference another API endpoint that represents
the linked element.

As decision drivers, performance and scalability often play a major role. Both
message size and the number of calls required to perform an integration should be
low, but these two desires stand in conflict with each other.

In terms of data privacy, a relationship source and target might have different
protection needs for example, a person and the credit card information belonging
to this person. This has to be considered, for instance, before embedding the
credit card information in a message requesting the persons data.

## Decisions about API Evolution

To be successful, APIs should expose stable contracts serving as a baseline for build-
ing applications on top of them; developer expectations and delivery guarantees have
to be balanced.

establish rules and policies to ensure that (1) the provider can improve and extend the
API and its implementation, and (2) the client can keep functioning with no or few
required changes for as long as possible.

### Strategies for Commissioning and Decommissioning

Many API providers are eager to bring new versions to production quickly. However,
they often overlook the importance of the ability to decommission old versions in
order not to be overwhelmed with maintenance effort and resulting cost.

Version Introducing and Decommissioning
- Two in Production
- Limited Lifetime Guarantee
- Aggressive Obsolescence: Announce a decommissioning date to be set as early as possible for the entire API
or its obsolete parts. Remove the deprecated API parts and the support for it as soon as the deadline
has passed.

Pattern: experimental preview

Problem: How can providers make the introduction of a new API (version) less risky for
their clients and obtain early adopter feedback without having to freeze the API
design prematurely?
Solution: Provide access to an API on a best-effort base without making any commitments
about the functionality offered, stability, and longevity. Clearly and explicitly
articulate this lack of API maturity to manage client expectations.
