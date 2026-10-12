/* Ghidra pseudocode, not original source.
 * ev_df72e9ec6d097d98265581ff35a2e461cddfe69d3931fceba3802c9eedcc8d52
 * Entry: 0x63eb30; label: FUN_0063eb30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0063eb30(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  
  if (DAT_0291389c != 0) {
    iVar4 = 0;
    pcVar5 = (char *)(DAT_0291389c + 0x5c);
    do {
      if (*pcVar5 == '\0') {
        puVar2 = (undefined4 *)(iVar4 * 0x8c + 4 + DAT_0291389c);
        if (puVar2 != (undefined4 *)0x0) {
          DAT_029139bc = 0;
          *puVar2 = DAT_0095e5c8;
          puVar2[1] = DAT_0095e5cc;
          puVar2[2] = DAT_0095e5d0;
          puVar2[0xf] = _DAT_0080fef0;
          uVar3 = _DAT_0080fef4;
          *(byte *)((int)puVar2 + 0x59) = *(byte *)((int)puVar2 + 0x59) & 0xfe;
          puVar2[0x10] = uVar3;
          *(undefined1 *)(puVar2 + 0x16) = 2;
          *(undefined2 *)((int)puVar2 + 0x5e) = 0;
          puVar2[9] = 0x3f800000;
          *(undefined2 *)(puVar2 + 0x18) = 0;
          puVar2[10] = 0x3f800000;
          *(undefined2 *)((int)puVar2 + 0x5a) = 0;
          puVar2[0xb] = 0x3f800000;
          *(undefined2 *)(puVar2 + 0x17) = 0;
          puVar1 = puVar2 + 3;
          puVar2[0xc] = 0x3f000000;
          puVar2[0xd] = 0x3f000000;
          puVar2[0xe] = 0x3f000000;
          puVar2[0x11] = 0x3dcccccd;
          puVar2[0x12] = 0x3dcccccd;
          puVar2[0x13] = 0x3dcccccd;
          puVar2[0x14] = 0x3dcccccd;
          puVar2[0x15] = 0;
          *puVar1 = DAT_008065a0;
          puVar2[4] = DAT_008065a4;
          uVar3 = DAT_008065a8;
          puVar2[0x19] = 0;
          puVar2[5] = uVar3;
          FUN_005b35a0(puVar1,puVar1,0);
          FUN_005b3620(puVar1,puVar1,(int)*(short *)(puVar2 + 0x17));
          *(undefined1 *)((int)puVar2 + 0x79) = 0xff;
          *(undefined1 *)((int)puVar2 + 0x7a) = 0xff;
          *(undefined1 *)((int)puVar2 + 0x7b) = 0;
          puVar2[0x1f] = DAT_0291389c + 4;
          *(undefined2 *)(puVar2 + 0x20) = DAT_02973aa0;
        }
        return puVar2;
      }
      iVar4 = iVar4 + 1;
      pcVar5 = pcVar5 + 0x8c;
    } while (iVar4 < 0x80);
  }
  return (undefined4 *)0x0;
}

