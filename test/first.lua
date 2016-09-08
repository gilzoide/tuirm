local tuirm = require 'tuirm'

app = tuirm.App ()
app:pause ()

print (app, getmetatable (app))

app:resume ()

app:run ()
