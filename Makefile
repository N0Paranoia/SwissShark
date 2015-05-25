.PHONY: clean All

All:
	@echo "----------Building project:[ SwissShak - Debug ]----------"
	@$(MAKE) -f  "SwissShak.mk"
clean:
	@echo "----------Cleaning project:[ SwissShak - Debug ]----------"
	@$(MAKE) -f  "SwissShak.mk" clean
