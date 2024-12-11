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
          default = pkgs.stdenv.mkDerivation {
            name = "ascii-weather";
            version = "1.0.0";
            src = ./.;
            buildInputs = with pkgs; [ gnumake gcc ncurses ];
            buildPhase = "make build";
            installPhase = ''
              mkdir -p $out/bin
              cp ascii-weather $out/bin
            '';
            meta = with pkgs.lib; {
              description =
                "An ascii screensaver displaying different weather types";
              homepage = "https://github.com/NewDawn0/asciiWeather";
              license = licenses.mit;
              maintainers = [ NewDawn0 ];
              platforms = platforms.all;
            };
          };
        });
    };
}
