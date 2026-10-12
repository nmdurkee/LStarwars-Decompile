/* Ghidra pseudocode, not original source.
 * ev_c8c236b59c094db138f75ad711126508fb50275f6e5d8f12ab0ad6308e4435ce
 * Entry: 0x495e80; label: FUN_00495e80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00495e80(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1;
  if (*(int *)(param_1 + 100) == 0) {
    if (*(int *)(param_1 + 0x68) == 0) {
      return;
    }
  }
  else {
    iVar1 = FUN_0055c780(PTR_DAT_00802c54);
    if (iVar1 == 0) {
      if (*(int *)(iVar2 + 0x34) == 0) {
        if (DAT_0093b338 != 0) {
          FUN_0057a6d0(DAT_00951b88,0xffffffff,0xffffffff,1);
          DAT_00800940 = FUN_00547990(0x30);
          return;
        }
        iVar2 = FUN_0055c780(PTR_DAT_00802c54);
        if (iVar2 == 0) {
          if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_00951b94) {
            FUN_004f42d0(0,0);
            FUN_004f42d0(1,0);
            FUN_0057a6d0(DAT_00951b88,0xffffffff,0xffffffff,0);
          }
          else {
            FUN_0057a6d0(DAT_00951b94,0xffffffff,0xffffffff,1);
            if ((((DAT_0093b324 != 0) && (DAT_00802af8 != -1)) &&
                (0 < *(int *)(&DAT_007f9f5c + DAT_007fa198 * 4))) &&
               ((int)(&DAT_00879544)[DAT_00802af8] < (int)(&DAT_00879544)[DAT_00802af8 == 0])) {
              (&DAT_0087956c)[DAT_00802af8 == 0] = (&DAT_0087956c)[DAT_00802af8 == 0] + 1;
              DAT_00800940 = FUN_00547990(0x30);
              return;
            }
          }
          DAT_00800940 = FUN_00547990(0x30);
          return;
        }
        DAT_00951b80 = iVar2;
        DAT_00800940 = FUN_00547990(0x30);
        return;
      }
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x34);
      if (iVar2 == 0) {
        FUN_0057a6d0(DAT_00951b94,0xffffffff,0xffffffff,1);
        DAT_00800940 = FUN_00547990(0x30);
        return;
      }
      if (iVar2 == 1) {
        DAT_0087b720 = iVar2;
        DAT_00951b80 = iVar1;
        param_1 = iVar2;
        FUN_005b1220(&param_1,0);
        DAT_00800940 = FUN_00547990(0x30);
        return;
      }
    }
  }
  FUN_00509ab0();
  DAT_00800940 = FUN_00547990(0x31);
  return;
}

