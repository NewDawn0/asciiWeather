{
  description = "An ascii weather screensaver";

  inputs.utils.url = "github:NewDawn0/nixUtils";

  outputs = { self, utils, ... }: {
    overlays.default = final: prev: {
      ascii-weather = self.packages.${prev.system}.default;
    };
    packages = utils.lib.eachSystem { } (pkgs: {
      default = pkgs.gccStdenv.mkDerivation {
        pname = "ascii-weather";
        version = "1.0.0";
        src = ./.;
        buildInputs = with pkgs; [ ncurses ];
        installPhase = "install -D ascii-weather -t $out/bin";
        meta = {
          description =
            "ASCII-based screensaver that shows various weather conditions";
          longDescription = ''
            This screensaver uses ASCII art to display different weather types.
            It's a creative and simple way to keep your terminal lively while providing weather updates.
          '';
          homepage = "https://github.com/NewDawn0/asciiWeather";
          license = pkgs.lib.licenses.mit;
          maintainers = with pkgs.lib.maintainers; [ NewDawn0 ];
          platforms = pkgs.lib.platforms.all;
        };
      };
    });
  };
}
