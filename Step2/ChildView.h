/**
 * \file ChildView.h
 *
 * \author Nick Katarzynski
 *
 * Class that implements the child window our program draws in.
 *
 * The window is a child of the main frame, which holds this
 * window, the menu bar, and the status bar.
 */

#pragma once
#include "Aquarium.h"

 /**
  * The child window our program draws in.
  */
class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:
    /// Any item we are currently dragging
    std::shared_ptr<CItem> mGrabbedItem;

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions

private:
    /// An object that describes our aquarium
    CAquarium  mAquarium;

    /// True until the first time we draw
    bool mFirstDraw = true;

    long long mLastTime;    ///< Last time we read the timer
    double mTimeFreq;       ///< Rate the timer updates

protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAddfishBetafish();
//	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg void OnAddfishClownfish();
    afx_msg void OnAddfishGoldeen();
	afx_msg void OnAdddecorCastle();
	afx_msg void OnFileSaveas();
	afx_msg void OnFileOpen32777();
    afx_msg void OnTimer(UINT_PTR nIDEvent);
};

