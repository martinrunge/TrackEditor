/*
 * Track.h
 *
 *  Created on: 03.08.2008
 *      Author: martin
 */

#ifndef TRACK_H_
#define TRACK_H_

#include "TrackPoint.h"
#include "CommonAttributes.h"
#include "CommonTrackAttributes.h"

#include <QList>
#include <QDateTime>
#include <QStandardItem>

class Track :public QList<TrackPoint*> , public QStandardItem, public CommonAttributes, public CommonTrackAttributes {
public:
	Track();
	virtual ~Track();

	double getMinLat();
	double getMaxLat();
	double getMinLong();
	double getMaxLong();

	double getMinX();
	double getMaxX();
	double getMinY();
	double getMaxY();

	QDateTime getTrackBegin();
	QDateTime getTrackEnd();

	void setIndex(int index);
	int getIndex();
	bool validIndex(void);

	void dataChanged(int column);
	QList<QStandardItem*> getItemList();

	void commit();

	inline void setPJ(PJ* pj) {m_pj = pj; };


private:
	void initMetaData();

	double distance(TrackPoint* tp1, TrackPoint* tp2);
	double speed(TrackPoint* tp1, TrackPoint* tp2);
	double speed(TrackPoint* tp1, TrackPoint* tp2, double dist_in_m);

	PJ* m_pj;

	double m_min_lat, m_max_lat, m_min_lng, m_max_lng;
	double m_min_x, m_max_x, m_min_y, m_max_y;

	QDateTime m_min_time, m_max_time;

	QList<QStandardItem*> m_itemlist;

	QStandardItem* m_index_item;
	QStandardItem* m_start_time_item;
	QStandardItem* m_end_time_item;
	QStandardItem* m_name_item;
	QStandardItem* m_num_points_item;



	// <number> xsd:nonNegativeInteger </number> [0..1] ?
	int m_track_index;

};

#endif /* TRACK_H_ */
