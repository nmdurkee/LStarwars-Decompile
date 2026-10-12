/* Ghidra analysis pseudocode, not original source.
 * ev_e26d15e716f54b37dc9752c5bbece96131eaa1b0064d3ed9476ea38cc0029dc6
 * Entry: 0x631890; label: FUN_00631890
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00631890(undefined4 param_1,int *param_2)

{
  code *pcVar1;
  undefined4 unaff_retaddr;
  undefined4 local_10 [2];
  undefined4 uStack_8;
  
  FUN_006312f0();
  (**(code **)(*param_2 + 0x20))(param_2,0,local_10);
  DAT_029131cc = (undefined4 *)FUN_004eef40(0x28,".\\pc\\Bink\\dsplay_bink.cpp",0x173);
  if (DAT_029131cc == (undefined4 *)0x0) {
    return 0;
  }
  FUN_00631e90(param_2,local_10[0],DAT_029131cc);
  DAT_029131cc[9] = DAT_0297660c >> 8 & 1;
  *DAT_029131cc = param_2;
  DAT_029131cc[1] = unaff_retaddr;
  pcVar1 = _BinkOpenDirectSound_4_exref;
  DAT_029131cc[2] = uStack_8;
  _DAT_029131d0 = param_1;
  _BinkSetSoundSystem_8(pcVar1,param_1);
  _DAT_029131fc = uStack_8;
  return 1;
}

