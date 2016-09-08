function onInit ()
	self.text = ''
	self.focus = 0
	self:style (tuirm.attr.UNDERLINE)
end

function onKeyPressed (key)
	if tuirm.isASC (key) then
		self.text = self.text .. key
	elseif key == tuirm.key.CTRL_U then
		self.text = ''
	elseif key == tuirm.key.RIGHT then
		self.focus = math.max (self.focus + 1, #self.text)
	end
end
