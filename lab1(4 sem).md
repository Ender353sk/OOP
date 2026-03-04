# Lab 1: Variant 5

## Functional Requirements

1. A user can send a message to another user.
2. A message has a lifecycle (created → sent → delivered → read).
3. A user can edit a previously sent message.
4. A user can delete a message:
* Delete for me (local deletion)
* Delete for everyone (global deletion)

5. The system must:
* Store messages persistently
* Deliver them asynchronously
* Track delivery and read status
* Maintain an audit trail of edits and deletions

6. The recipient may be online or offline.

# Part 1 — Component Diagram (30%)
## Components & Responsibilities
1. Client (Web / Mobile)
* Send/edit/delete messages
* Display message status
* Send delivery/read acknowledgments
* Render edit history indicator

2. Backend API
* Authentication & authorization
* Validate edit/delete permissions
* Expose REST endpoints
* Forward requests to Message Service

3. Message Service
* Create messages
* Handle message updates
* Manage deletion logic
* Maintain message state
* Record audit history

4. Audit Service
* Store message versions
* Track who edited/deleted and when
* Provide audit history for compliance

5. Database
* Store messages
* Store message versions
* Store deletion metadata
* Store status information

6. Delivery Mechanism (Queue + WebSocket)
* Asynchronous message delivery
* Handle offline users
* Notify clients about edits/deletions
  
## Component Diagram (Mermaid)
'''mermaid
graph LR
  Client --> API
  API --> MessageService
  MessageService --> DB[(Messages DB)]
  MessageService --> AuditService
  MessageService --> Queue
  Queue --> DeliveryService
  DeliveryService --> Client
'''










