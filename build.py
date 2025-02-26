import sys
import os
import platform
import subprocess

def get_linux_distro():
    """Check the Linux distribution using /etc/os-release."""
    try:
        with open("/etc/os-release", "r") as f:
            os_release = f.read()
            if "ubuntu" in os_release.lower():
                return "ubuntu"
            elif "fedora" in os_release.lower():
                return "fedora"
            else:
                return "unknown"
    except FileNotFoundError:
        return "unknown"

def main():
    current_platform = platform.system().lower()

    script_folders = {
        "windows": "windows",
        "darwin": "macos",
        "linux": get_linux_distro(),
    }

    script_folder = script_folders.get(current_platform, "unknown")

    if script_folder == "unknown":
        print(f"Error: Unsupported platform '{current_platform}' or unknown Linux distribution.")
        sys.exit(1)

    if len(sys.argv) < 2:
        print("Usage: python build.py <script_name>")
        sys.exit(1)

    script_name = sys.argv[1]

    script_extension = ".ps1" if current_platform == "windows" else ".sh"
    script_path = os.path.join("scripts", script_folder, f"{script_name}{script_extension}")

    if not os.path.exists(script_path):
        print(f"Error: Script '{script_path}' not found.")
        sys.exit(1)

    try:
        if current_platform == "windows":
            subprocess.run(["powershell", "-ExecutionPolicy", "Bypass", "-File", script_path], check=True)
        else:
            subprocess.run(["/bin/bash", script_path], check=True)
    except subprocess.CalledProcessError as e:
        print(f"Error: Script '{script_path}' failed with exit code {e.returncode}.")
        sys.exit(e.returncode)

if __name__ == "__main__":
    main()
