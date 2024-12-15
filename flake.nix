{
  description = "An ascii weather screensaver";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs";
    nix-systems.url = "github:nix-systems/default";
  };

  outputs = { nixpkgs, ... }@inputs:
    let
      eachSystem = nixpkgs.lib.genAttrs (import inputs.nix-systems);
      mkPkgs = system: nixpkgs.legacyPackages.${system};
    in {
      packages = eachSystem (system:
        let pkgs = mkPkgs system;
        in {
          default = pkgs.gccStdenv.mkDerivation {
            pname = "ascii-weather";
            version = "1.0.0";
            src = ./.;
            buildInputs = with pkgs; [ ncurses ];
            installPhase = "install -D ascii-weather -t $out/bin";
            meta = {
              description =
                "An ASCII-based screensaver that shows various weather conditions";
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
