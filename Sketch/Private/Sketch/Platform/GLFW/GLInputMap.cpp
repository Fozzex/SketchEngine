#include "GLInputMap.h"

namespace sk
{
	std::unordered_map<int, Keyboard> GLInputMap<Keyboard>::s_Map =
	{
		{ GLFW_KEY_UNKNOWN      , Keyboard::Unknown      },
		{ GLFW_KEY_SPACE        , Keyboard::Space        },
		{ GLFW_KEY_APOSTROPHE   , Keyboard::Apostrophe   },
		{ GLFW_KEY_COMMA        , Keyboard::Comma        },
		{ GLFW_KEY_MINUS        , Keyboard::Minus        },
		{ GLFW_KEY_PERIOD       , Keyboard::Period       },
		{ GLFW_KEY_SLASH        , Keyboard::Slash        },
		{ GLFW_KEY_0            , Keyboard::Num0         },
		{ GLFW_KEY_1            , Keyboard::Num1         },
		{ GLFW_KEY_2            , Keyboard::Num2         },
		{ GLFW_KEY_3            , Keyboard::Num3         },
		{ GLFW_KEY_4            , Keyboard::Num4         },
		{ GLFW_KEY_5            , Keyboard::Num5         },
		{ GLFW_KEY_6            , Keyboard::Num6         },
		{ GLFW_KEY_7            , Keyboard::Num7         },
		{ GLFW_KEY_8            , Keyboard::Num8         },
		{ GLFW_KEY_9            , Keyboard::Num9         },
		{ GLFW_KEY_SEMICOLON    , Keyboard::Semicolon    },
		{ GLFW_KEY_EQUAL        , Keyboard::Equal        },
		{ GLFW_KEY_A            , Keyboard::A            },
		{ GLFW_KEY_B            , Keyboard::B            },
		{ GLFW_KEY_C            , Keyboard::C            },
		{ GLFW_KEY_D            , Keyboard::D            },
		{ GLFW_KEY_E            , Keyboard::E            },
		{ GLFW_KEY_F            , Keyboard::F            },
		{ GLFW_KEY_G            , Keyboard::G            },
		{ GLFW_KEY_H            , Keyboard::H            },
		{ GLFW_KEY_I            , Keyboard::I            },
		{ GLFW_KEY_J            , Keyboard::J            },
		{ GLFW_KEY_K            , Keyboard::K            },
		{ GLFW_KEY_L            , Keyboard::L            },
		{ GLFW_KEY_M            , Keyboard::M            },
		{ GLFW_KEY_N            , Keyboard::N            },
		{ GLFW_KEY_O            , Keyboard::O            },
		{ GLFW_KEY_P            , Keyboard::P            },
		{ GLFW_KEY_Q            , Keyboard::Q            },
		{ GLFW_KEY_R            , Keyboard::R            },
		{ GLFW_KEY_S            , Keyboard::S            },
		{ GLFW_KEY_T            , Keyboard::T            },
		{ GLFW_KEY_U            , Keyboard::U            },
		{ GLFW_KEY_V            , Keyboard::V            },
		{ GLFW_KEY_W            , Keyboard::W            },
		{ GLFW_KEY_X            , Keyboard::X            },
		{ GLFW_KEY_Y            , Keyboard::Y            },
		{ GLFW_KEY_Z            , Keyboard::Z            },
		{ GLFW_KEY_LEFT_BRACKET , Keyboard::LeftBracket  },
		{ GLFW_KEY_BACKSLASH    , Keyboard::Backslash    },
		{ GLFW_KEY_RIGHT_BRACKET, Keyboard::RightBracket },
		{ GLFW_KEY_GRAVE_ACCENT , Keyboard::Grave        },

		{ GLFW_KEY_ESCAPE       , Keyboard::Escape       },
		{ GLFW_KEY_ENTER        , Keyboard::Enter        },
		{ GLFW_KEY_TAB          , Keyboard::Tab          },
		{ GLFW_KEY_BACKSPACE    , Keyboard::Backspace    },
		{ GLFW_KEY_INSERT       , Keyboard::Insert       },
		{ GLFW_KEY_DELETE       , Keyboard::Delete       },
		{ GLFW_KEY_RIGHT        , Keyboard::Right        },
		{ GLFW_KEY_LEFT         , Keyboard::Left         },
		{ GLFW_KEY_DOWN         , Keyboard::Down         },
		{ GLFW_KEY_UP           , Keyboard::Up           },
		{ GLFW_KEY_PAGE_UP      , Keyboard::PageUp       },
		{ GLFW_KEY_PAGE_DOWN    , Keyboard::PageDown     },
		{ GLFW_KEY_HOME         , Keyboard::Home         },
		{ GLFW_KEY_END          , Keyboard::End          },
		{ GLFW_KEY_CAPS_LOCK    , Keyboard::CapsLock     },
		{ GLFW_KEY_SCROLL_LOCK  , Keyboard::ScrollLock   },
		{ GLFW_KEY_NUM_LOCK     , Keyboard::NumLock      },
		{ GLFW_KEY_PRINT_SCREEN , Keyboard::PrintScreen  },
		{ GLFW_KEY_PAUSE        , Keyboard::Pause        },
		{ GLFW_KEY_F1           , Keyboard::F1           },
		{ GLFW_KEY_F2           , Keyboard::F2           },
		{ GLFW_KEY_F3           , Keyboard::F3           },
		{ GLFW_KEY_F4           , Keyboard::F4           },
		{ GLFW_KEY_F5           , Keyboard::F5           },
		{ GLFW_KEY_F6           , Keyboard::F6           },
		{ GLFW_KEY_F7           , Keyboard::F7           },
		{ GLFW_KEY_F8           , Keyboard::F8           },
		{ GLFW_KEY_F9           , Keyboard::F9           },
		{ GLFW_KEY_F10          , Keyboard::F10          },
		{ GLFW_KEY_F11          , Keyboard::F11          },
		{ GLFW_KEY_F12          , Keyboard::F12          },
		{ GLFW_KEY_F13          , Keyboard::F13          },
		{ GLFW_KEY_F14          , Keyboard::F14          },
		{ GLFW_KEY_F15          , Keyboard::F15          },
		{ GLFW_KEY_F16          , Keyboard::F16          },
		{ GLFW_KEY_F17          , Keyboard::F17          },
		{ GLFW_KEY_F18          , Keyboard::F18          },
		{ GLFW_KEY_F19          , Keyboard::F19          },
		{ GLFW_KEY_F20          , Keyboard::F20          },
		{ GLFW_KEY_F21          , Keyboard::F21          },
		{ GLFW_KEY_F22          , Keyboard::F22          },
		{ GLFW_KEY_F23          , Keyboard::F23          },
		{ GLFW_KEY_F24          , Keyboard::F24          },
		{ GLFW_KEY_F25          , Keyboard::F25          },
		{ GLFW_KEY_KP_0         , Keyboard::KP_0         },
		{ GLFW_KEY_KP_1         , Keyboard::KP_1         },
		{ GLFW_KEY_KP_2         , Keyboard::KP_2         },
		{ GLFW_KEY_KP_3         , Keyboard::KP_3         },
		{ GLFW_KEY_KP_4         , Keyboard::KP_4         },
		{ GLFW_KEY_KP_5         , Keyboard::KP_5         },
		{ GLFW_KEY_KP_6         , Keyboard::KP_6         },
		{ GLFW_KEY_KP_7         , Keyboard::KP_7         },
		{ GLFW_KEY_KP_8         , Keyboard::KP_8         },
		{ GLFW_KEY_KP_9         , Keyboard::KP_9         },
		{ GLFW_KEY_KP_DECIMAL   , Keyboard::KP_Decimal   },
		{ GLFW_KEY_KP_DIVIDE    , Keyboard::KP_Divide    },
		{ GLFW_KEY_KP_MULTIPLY  , Keyboard::KP_Multiply  },
		{ GLFW_KEY_KP_SUBTRACT  , Keyboard::KP_Subtract  },
		{ GLFW_KEY_KP_ADD       , Keyboard::KP_Add       },
		{ GLFW_KEY_KP_ENTER     , Keyboard::KP_Enter     },
		{ GLFW_KEY_KP_EQUAL     , Keyboard::KP_Equal     },
		{ GLFW_KEY_LEFT_SHIFT   , Keyboard::LeftShift    },
		{ GLFW_KEY_LEFT_CONTROL , Keyboard::LeftControl  },
		{ GLFW_KEY_LEFT_ALT     , Keyboard::LeftAlt      },
		{ GLFW_KEY_LEFT_SUPER   , Keyboard::LeftSuper    },
		{ GLFW_KEY_RIGHT_SHIFT  , Keyboard::RightShift   },
		{ GLFW_KEY_RIGHT_CONTROL, Keyboard::RightControl },
		{ GLFW_KEY_RIGHT_ALT    , Keyboard::RightAlt     },
		{ GLFW_KEY_RIGHT_SUPER  , Keyboard::RightSuper   },
		{ GLFW_KEY_MENU         , Keyboard::Menu         },
	};

	std::unordered_map<int, Mouse> GLInputMap<Mouse>::s_Map =
	{
		{ GLFW_MOUSE_BUTTON_1, Mouse::Button1 },
		{ GLFW_MOUSE_BUTTON_2, Mouse::Button2 },
		{ GLFW_MOUSE_BUTTON_3, Mouse::Button3 },
		{ GLFW_MOUSE_BUTTON_4, Mouse::Button4 },
		{ GLFW_MOUSE_BUTTON_5, Mouse::Button5 },
		{ GLFW_MOUSE_BUTTON_6, Mouse::Button6 },
		{ GLFW_MOUSE_BUTTON_7, Mouse::Button7 },
		{ GLFW_MOUSE_BUTTON_8, Mouse::Button8 }
	};
}
