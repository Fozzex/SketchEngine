#pragma once

namespace sk
{
	template<class Device>
	class DeviceHandle
	{
	public:

		DeviceHandle(Device* device)
			: m_Device(device) {}

	protected:

		Device* m_Device;

	};
}
