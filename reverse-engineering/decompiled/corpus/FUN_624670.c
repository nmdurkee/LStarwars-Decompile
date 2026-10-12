/* Ghidra analysis pseudocode, not original source.
 * ev_0d221f2c9357ed308f9b597510bd130964f67481868d3ff45e1443ef5eb3d7b9
 * Entry: 0x624670; label: FUN_00624670
 */

undefined4 FUN_00624670(undefined4 param_1)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  uint local_8;
  undefined4 local_4;
  
  iVar2 = FUN_006d6940(&local_8);
  FUN_004f1ff0(in_EAX + 0x4c);
  if (iVar2 != -1) {
    switch(iVar2) {
    case 1:
    case 0x1c:
      if (*(code **)(in_EAX + 0x15c) != (code *)0x0) {
        (**(code **)(in_EAX + 0x15c))(param_1);
        return 0;
      }
      break;
    default:
      cVar1 = FUN_0061e6b0(iVar2,local_8 & 1);
      local_4 = CONCAT31(local_4._1_3_,cVar1);
      if (cVar1 != '\0') {
        FUN_00619e60(local_4);
      }
      break;
    case 0xe:
    case 0xd3:
      FUN_00619f20();
      return 0;
    case 200:
      FUN_00619ce0();
      return 0;
    case 0xcb:
      FUN_00619d40();
      return 0;
    case 0xcd:
      FUN_00619d70();
      return 0;
    case 0xd0:
      FUN_00619d10();
      return 0;
    }
  }
  return 0;
}

