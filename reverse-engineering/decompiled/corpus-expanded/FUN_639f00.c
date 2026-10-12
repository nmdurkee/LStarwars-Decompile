/* Ghidra pseudocode, not original source.
 * ev_8263a5d3e8c49c8909e3cfceaf1282da1bb42b3174c131367c36677ef6ae0531
 * Entry: 0x639f00; label: FUN_00639f00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00639f00(int param_1)

{
  undefined4 uVar1;
  
  DAT_0291395c = FUN_00619250(0x46,0x46,0xdc,300,DAT_02912e80,FUN_00639ee0,"Level Defaults");
  if ((DAT_0291396c != 0) && (DAT_0291395c != 0)) {
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00639d40,0,0x40800000,
                         *(undefined4 *)(DAT_0291396c + 0x14),"Global Scale/Intensity");
    FUN_00618e10(DAT_0291395c,uVar1);
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00639cc0,0,0x43340000,
                         *(undefined4 *)(DAT_0291396c + 4),"Start Angle");
    FUN_00618e10(DAT_0291395c,uVar1);
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00639ce0,0,0x3f800000,
                         *(undefined4 *)(DAT_0291396c + 8),"Min Intensity");
    FUN_00618e10(DAT_0291395c,uVar1);
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00639d00,0,0x43340000,
                         *(undefined4 *)(DAT_0291396c + 0xc),"End Angle");
    FUN_00618e10(DAT_0291395c,uVar1);
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00639d20,0,0x3f800000,
                         *(undefined4 *)(DAT_0291396c + 0x10),"Max Intensity");
    FUN_00618e10(DAT_0291395c,uVar1);
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00639d60,0,0x40800000,
                         *(undefined4 *)(DAT_0291396c + 0x1c),"Flare/Dispersion");
    FUN_00618e10(DAT_0291395c,uVar1);
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00639d80,0,0x41200000,
                         *(undefined4 *)(DAT_0291396c + 0x20),"Fragment Glow Factor");
    FUN_00618e10(DAT_0291395c,uVar1);
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00639da0,0,0x40000000,
                         *(undefined4 *)(DAT_0291396c + 0x24),"Threshold");
    FUN_00618e10(DAT_0291395c,uVar1);
    uVar1 = FUN_00627bc0(0,&DAT_008109d8,*(int *)(DAT_0291396c + 0x28) != 0,1,FUN_00639dc0,
                         "Source Available");
    FUN_00618e10(DAT_0291395c,uVar1);
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00639de0,0xbf800000,0x40000000,
                         *(undefined4 *)(DAT_0291396c + 0x2c),"Source Direction X");
    FUN_00618e10(DAT_0291395c,uVar1);
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00639e00,0xbf800000,0x40000000,
                         *(undefined4 *)(DAT_0291396c + 0x30),"Source Direction Y");
    FUN_00618e10(DAT_0291395c,uVar1);
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00639e20,0xbf800000,0x40000000,
                         *(undefined4 *)(DAT_0291396c + 0x34),"Source Direction Z");
    FUN_00618e10(DAT_0291395c,uVar1);
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00639e40,0,0x43340000,
                         *(undefined4 *)(DAT_0291396c + 0x38),"Source Inner Radius");
    FUN_00618e10(DAT_0291395c,uVar1);
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00639e60,0,0x3f800000,
                         *(undefined4 *)(DAT_0291396c + 0x3c),"Source Inner Intensity");
    FUN_00618e10(DAT_0291395c,uVar1);
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00639e80,0,0x43340000,
                         *(undefined4 *)(DAT_0291396c + 0x40),"Source Outer Radius");
    FUN_00618e10(DAT_0291395c,uVar1);
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00639ea0,0,0x3f800000,
                         *(undefined4 *)(DAT_0291396c + 0x44),"Source Outer Intensity");
    FUN_00618e10(DAT_0291395c,uVar1);
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00639ec0,0,0x41200000,
                         *(undefined4 *)(DAT_0291396c + 0x48),"Source FallOff Power");
    FUN_00618e10(DAT_0291395c,uVar1);
    FUN_006279b0(param_1,DAT_0291395c);
    *(int *)(DAT_0291395c + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_0291395c + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

