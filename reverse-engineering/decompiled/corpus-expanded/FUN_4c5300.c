/* Ghidra pseudocode, not original source.
 * ev_e691f105e7e9df146417299401ecc100ef54520e911e9eb278e110fa7bbc9740
 * Entry: 0x4c5300; label: FUN_004c5300
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004c5300(undefined4 param_1,undefined4 param_2,int param_3,float param_4,ushort param_5,
                 ushort param_6,ushort param_7)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 *unaff_ESI;
  uint local_58;
  uint local_54;
  uint local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [48];
  undefined4 local_10;
  float local_c;
  undefined4 local_8;
  
  if ((in_EAX != 0) && (unaff_ESI != (undefined4 *)0x0)) {
    iVar1 = in_EAX + 0x68;
    iVar2 = FUN_005cfac0(iVar1);
    if (iVar2 != 0) {
      local_58 = (uint)param_5;
      local_54 = (uint)param_6;
      local_50 = (uint)param_7;
      thunk_FUN_005b5300(local_40,&local_58);
      local_44 = param_1;
      local_48 = param_1;
      local_4c = param_1;
      thunk_FUN_005b4a50(local_40,&local_4c);
      local_10 = *unaff_ESI;
      local_8 = unaff_ESI[2];
      local_c = (float)unaff_ESI[1] + param_4;
      if (param_3 != 0) {
        FUN_005f33b0(iVar1,local_40);
        return;
      }
      FUN_005ff7a0(iVar1,local_40,param_2);
    }
  }
  return;
}

