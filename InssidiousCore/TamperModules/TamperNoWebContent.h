#include "TamperModule.h"
#include "TamperTypes.h"

class TamperNoWebContent : public TamperModule
{
public:
	TamperNoWebContent(void** ppTamperConfig);

	short process(PacketList* packetList) override;

private:
	TamperNoWebContentConfig** ppNoWebContentConfig;
};