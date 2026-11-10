-- Replaces kmonad's `cmd-button "open -a ..."` aliases.
-- Copy into ~/.hammerspoon/init.lua (or `require` it), then Reload Config.
-- The P65 sends Hyper (ctrl+opt+cmd+shift) + key while `a` is held.
local hyper = { "ctrl", "alt", "cmd", "shift" }

local apps = {
  s = "Sublime Text.app",
  g = "Gmail.app",
  u = "Jetski Web.app",
  j = "Cider.app",
  k = "Google Chrome.app",
  l = "Google Chrome Beta.app",
  c = "Google Chat.app",
  m = "Google Meet.app",
}

for key, app in pairs(apps) do
  hs.hotkey.bind(hyper, key, function()
    hs.task.new("/usr/bin/open", nil, { "-a", app }):start()
  end)
end
