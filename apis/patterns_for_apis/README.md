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
