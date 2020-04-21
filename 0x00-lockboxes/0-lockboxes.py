#!/usr/bin/python3
"""Module to solve the Lockboxes problem.
"""


def continue_iteration(status_map, expected, previous_status):
    """Verify if the keys map was checked or if it needs to be rechecked.

    Arguments:
        status_map (list): the map of keys for the boxes.
        expected (list): the expect map of keys(has the key for every box).
        previous_status (list): the previous map of checked keys to verify
                                if there aren't new keys to check.

    Returns:
        bool:   True if the map of keys is the expected,
                False if the map don't have the keys for every box,
                None if the map needs to be rechecked.
    """
    # If the map is the same it means that there aren't new keys.
    if status_map == previous_status:
        return False
    elif status_map == expected:
        return True
    # If the map has new keys and isn't finished then recheck the map.
    else:
        return None


def seek(box, status):
    """Updates the map with the boxes that can be opened with the new keys.

    Arguments:
        box (list):     a list with the keys(indexes) for other boxes.
        status (list):  the map with the status of every box to see
                        if the keys was found or not.

    Returns:
        list:   a updated list with the status of which keys
                are available to unlock boxes.
    """
    # Update the map with new keys.
    for key in box:
        status[key] = True
    return status


def canUnlockAll(boxes):
    """Determines if all the boxes can be opened.

    Arguments:
        boxes (list): a list of lists with keys to open other boxes(lists).

    Returns:
        bool: True if all boxes can be opened, else False.
    """
    num_of_boxes = len(boxes)
    map_unlocked_boxes = [True] + [False] * (num_of_boxes - 1)
    previous_map = []
    expected_output = [True] * num_of_boxes
    key = 0

    while key < num_of_boxes:
        # If the box is unlocked
        if map_unlocked_boxes[key]:
            # Update map
            map_unlocked_boxes = seek(boxes[key], map_unlocked_boxes)
        # If reached end of boxes list
        if key == (num_of_boxes - 1):
            # Check if the map is finished or need to recheck
            finished = continue_iteration(
                map_unlocked_boxes,
                expected_output,
                previous_map
            )
            if finished in (True, False):
                return finished
            else:
                # Recheck for boxes with new unlocked keys
                key = 0
                previous_map = map_unlocked_boxes.copy()
        key += 1
