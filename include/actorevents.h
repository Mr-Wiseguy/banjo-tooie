#ifndef __ACTOR_EVENTS_H__
#define __ACTOR_EVENTS_H__

typedef enum actor_event_e {
	EVENT_1F_ACTOR_ONSCREEN = 0x1F,
	EVENT_2E_ACTOR_DIALOG_ENDED = 0x2E,
	EVENT_3E_ACTOR_TOUCHED = 0x3E,
	EVENT_91_ACTOR_STOOD_ON = 0x91,
	EVENT_95_ACTOR_SPAWNED = 0x95
} ActorEventId;

#endif
