// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

// With inspiration from Hazel game engine by The Cherno
// https://github.com/TheCherno/Hazel/blob/f823e2e51854014032fbc18b1fa319294ef98321/Hazel/src/Hazel/Core/Log.h

namespace SymCiSo
{

	class Log
	{
	public:
		static void init();

		static std::shared_ptr<spdlog::logger>& get_core_logger() { return s_core_logger; }
		static std::shared_ptr<spdlog::logger>& get_client_logger() { return s_client_logger; }

	private:
		static std::shared_ptr<spdlog::logger> s_core_logger;
		static std::shared_ptr<spdlog::logger> s_client_logger;
	};

} // namespace SymCiSo

// Core log macros
#define SYMCISO_CORE_TRACE(...)    ::SymCiSo::Log::get_core_logger()->trace(__VA_ARGS__)
#define SYMCISO_CORE_INFO(...)     ::SymCiSo::Log::get_core_logger()->info(__VA_ARGS__)
#define SYMCISO_CORE_WARN(...)     ::SymCiSo::Log::get_core_logger()->warn(__VA_ARGS__)
#define SYMCISO_CORE_ERROR(...)    ::SymCiSo::Log::get_core_logger()->error(__VA_ARGS__)
#define SYMCISO_CORE_CRITICAL(...) ::SymCiSo::Log::get_core_logger()->critical(__VA_ARGS__)

// Client log macros
#define SYMCISO_TRACE(...)         ::SymCiSo::Log::get_client_logger()->trace(__VA_ARGS__)
#define SYMCISO_INFO(...)          ::SymCiSo::Log::get_client_logger()->info(__VA_ARGS__)
#define SYMCISO_WARN(...)          ::SymCiSo::Log::get_client_logger()->warn(__VA_ARGS__)
#define SYMCISO_ERROR(...)         ::SymCiSo::Log::get_client_logger()->error(__VA_ARGS__)
#define SYMCISO_CRITICAL(...)      ::SymCiSo::Log::get_client_logger()->critical(__VA_ARGS__)
