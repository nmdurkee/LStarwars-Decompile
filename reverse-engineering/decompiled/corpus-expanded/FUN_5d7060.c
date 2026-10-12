/* Ghidra pseudocode, not original source.
 * ev_2b55f789f1446a783af549e987f50963f158fc34aa4a0a7d53ec4780e4e01d82
 * Entry: 0x5d7060; label: FUN_005d7060
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d7060(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  short sVar1;
  ushort uVar2;
  char cVar3;
  int iVar4;
  byte *pbVar5;
  
  sVar1 = *(short *)(param_3 + 0x18);
  while( true ) {
    if (sVar1 == -1) {
      cVar3 = FUN_006042e0(param_3,param_3 + 0xc,&DAT_00806680,param_5,0);
      uVar2 = *(ushort *)(*(int *)(param_1 + 0x10) + (uint)*(ushort *)(param_3 + 0x1e) * 2);
      pbVar5 = (byte *)((uint)(uVar2 >> 2) + param_2);
      *pbVar5 = *pbVar5 | cVar3 << ((byte)uVar2 & 3) * '\x02';
      return;
    }
    iVar4 = FUN_006042e0(param_3,param_3 + 0xc,&DAT_00806680,param_5,1);
    if (iVar4 == 0) break;
    if (iVar4 == 1) {
      iVar4 = 0;
      if (*(short *)(param_3 + 0x1c) != 0) {
        do {
          uVar2 = *(ushort *)
                   (*(int *)(param_1 + 0x10) + ((uint)*(ushort *)(param_3 + 0x1e) + iVar4) * 2);
          pbVar5 = (byte *)((uint)(uVar2 >> 2) + param_2);
          iVar4 = iVar4 + 1;
          *pbVar5 = *pbVar5 | '\x01' << ((byte)uVar2 & 3) * '\x02';
        } while (iVar4 < (int)(uint)*(ushort *)(param_3 + 0x1c));
      }
      return;
    }
    FUN_005d7060(param_1,param_2,(uint)*(ushort *)(param_3 + 0x18) * 0x20 + *(int *)(param_1 + 0x18)
                 ,param_4,param_5,param_6);
    param_3 = (uint)*(ushort *)(param_3 + 0x1a) * 0x20 + *(int *)(param_1 + 0x18);
    sVar1 = *(short *)(param_3 + 0x18);
  }
  return;
}

