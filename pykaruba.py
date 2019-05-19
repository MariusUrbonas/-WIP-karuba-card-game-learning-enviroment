import enum
from copy import deepcopy
from typing import List
from __future__ import annotations

KarubaMoveVector = List[KarubaMove]
KarubaCardVector = List[KarubaCard]


class KarubaGame:
    """Game parameters describing a specific instance of Karuba."""

    def __init__(self, params=None):
        """
        Creates a HanabiGame object.

        Args:
          params: is a dictionary of parameters and their values.
          Possible parameters include
            "players": 2 <= number of players <= 4
            "rank_list": list of ranks for players, subset of {1,2,...,16}
                         default full
            "hand_size": 2 <= number of cards in player hand
            "max_information_tokens": 1 <= maximum (and initial) number of
                                      info tokens.
            "seed": random number seed. -1 to use system random device to get
                    seed.
            "observation_type": int AgentObservationType.
        """
        if params is None:
            raise "Parameters are None for KarubaGame constuctor"
        self.params = params

    def init_state(self):
        return KarubaState(self)

    def parameter_string(self) -> string:
        param_sting = 'Parameters:\n'
        for param in self.params:
            param_sting += '\t{}: {}'.format(param, self.params[param])


class HanabiEndOfGameType(enum.IntEnum):
    NOT_FINISHED = 0
    FINISHED = 1


class KarubaObservation:
    """Player's observed view of an environment KarubaState."""

    def __init__(self, state: KarubaState, game: KarubaGame, player: int):
        self._game = game
        self._state = state
        self._player = player

    def discard_pile(self) -> KarubaCardVector:
        """Returns a list of discarded card indexes for observing player."""
        return self._state.discard_pile(self.player)

    def legal_moves(self) -> KarubaMoveVector:
        """Returns a list of legal moves for observing player."""
        pass

    def board(self) -> KarubaBoard:
        pass

    def hand(self) -> KarubaCardVector:
        pass


class KarubaState(object):
    def __init__(self, game: KarubaGame, c_state=None):
        """
        Returns a new state.

        Args:
          game: KarubaGame describing the parameters for a game of Hanabi.
          c_state: C++ state to copy, or None for a new state.
        """
        if c_state is None:
            # Create initial game state
            self._state = []
        else:
            # copy c_state
            self._state = c_state

    def copy(self):
        return deepcopy(self)

    def observation(self, player: int) -> KarubaObservation:
        return KarubaObservation(self._state, self._game, player)

    def apply_move(self, move: KarubaMove) -> KarubaState:
        pass

    def deck_size(self):
        """Returns number of cards left in the deck."""
        pass

    def discard_pile(self, player: int) -> KarubaCardVector:
        """Returns a list of all discarded cards,
           in order they were discarded for a given player."""
        pass

    def player_hand(self, player: int) -> KarubaCardVector:
        """Returns a list of all cards currently in hand for a given player,
           with cards ordered oldest to newest."""
        pass

    def game_status(self) -> HanabiEndOfGameType:
        """Returns the end of game status,
           NOT_FINISHED if game is still active."""
        pass

    def is_terminal(self) -> bool:
        """Returns false if game is still active, true otherwise."""
        pass

    def move_is_legal(self, agent, move) -> bool:
        """Returns true if and only if move is legal for active agent."""
        pass

    def score(self, player: int) -> int:
        """
        Returns the game score at a terminal state for a given player.
        Win: 1
        Draw: 0
        Loss: -1

        NOTE: result is undefined when game is NOT_FINISHED.
        """
        pass

    def board_score(self, player: int) -> int:
        """Returns the board score for a given player."""
        pass
