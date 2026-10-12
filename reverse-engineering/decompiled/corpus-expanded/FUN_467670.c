/* Ghidra pseudocode, not original source.
 * ev_ea1530849940888f284d0032d7a98207406f19684b2cf3146fa9fb18feca4f87
 * Entry: 0x467670; label: FUN_00467670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00467670(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  undefined1 local_40 [64];
  
  if (param_2 != (int *)0x0) {
    iVar2 = 0;
    if (*(short *)((int)param_2 + 0xe) != 0) {
      puVar3 = (uint *)(*param_2 + 0xa0);
      do {
        if ((((*puVar3 & 2) != 0) && ((char)*puVar3 < '\0')) &&
           (((short)puVar3[-8] < 0 ||
            (*(char *)((int)(short)puVar3[-8] + *(int *)(param_1 + 0x2a94)) != '\0')))) {
          thunk_FUN_005d05b0();
          if ((puVar3[-0xb] & 4) != 0) {
            FUN_005a16b0(puVar3[-0x1e],2,puVar3[-0xd],0);
          }
          if ((puVar3[-0xb] & 0x1000) == 0) {
            FUN_00596920(0);
          }
          if ((((puVar3[-0xb] & 0x40) != 0) && ((*puVar3 & 0x800) != 0)) &&
             (*(int *)(puVar3[-0x1e] + 0x18) != 0)) {
            iVar1 = FUN_005d0330(*(int *)(puVar3[-0x1e] + 0x18) + 4);
            FUN_005f33b0(puVar3 + -0x1d,iVar1);
            if (((puVar3[-0xb] & 4) != 0) &&
               (iVar1 = FUN_00550490(iVar1,2,(float)puVar3[-0xd] + *(float *)(iVar1 + 0x34),
                                     *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc0),
                                     local_40), iVar1 != 0)) {
              FUN_005d4690(0);
              FUN_005f33b0(puVar3 + -0x1d,local_40);
              FUN_005d46b0();
            }
          }
        }
        iVar2 = iVar2 + 1;
        puVar3 = puVar3 + 0x29;
      } while (iVar2 < (int)(uint)*(ushort *)((int)param_2 + 0xe));
    }
    thunk_FUN_005d05b0();
  }
  return;
}

