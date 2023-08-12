#include <stdio.h>
#include <string.h>

void encrypt(char plaintxt[], int key)
{
	int i = 0;
	char ch;

	for (i; plaintxt[i] != '\0'; i++)
	{
		// breaks each letter to encrypt
		ch = plaintxt[i];

		// encryption logic
		if (ch >= 'A' && ch <= 'Z')
			ch = (ch + key - 'A') % 26 + 'A';

		else if (ch >= 'a' && ch <= 'z')
			ch = (ch + key - 'a') % 26 + 'a';

		// storing encrypted letter back to array
		plaintxt[i] = ch;
	}
	printf("\nEncrypted text : %s", plaintxt);
	printf("\n");
}

void decrypt(char ciphertxt[], int key)
{
	int i = 0;
	char ch;

	for (i; ciphertxt[i] != '\0'; i++)
	{
		// breaks each letter to decrypt
		ch = ciphertxt[i];

		// decryption logic
		if (ch >= 'A' && ch <= 'Z')
			ch = (ch - key + 26 - 'a') % 26 + 'a';

		else if (ch >= 'a' && ch <= 'z')
			ch = (ch - key + 26 - 'a') % 26 + 'a';

		// storing decrypted letter back to array

		ciphertxt[i] = ch;
	}
	printf("\nDecrypted text : %s", ciphertxt);
	printf("\n");
}
int main()
{
	char plaintxt[100], ciphertxt[100];
	int choice, key;

	do
	{
		printf("\n To encrypt, press '1' :");
		printf("\n To decrypt, press '2' :");
		printf("\n To exit, press '0' to exit.");

		printf("\n Enter your choice : ");
		scanf("%d", &choice);

		if (choice == 1)
		{
			printf("Enter Key :");
			scanf("%d", &key);
			printf("Input text to encrypt->");
			scanf("%s", &plaintxt);
			encrypt(plaintxt, key);
		}
		else if (choice == 2)
		{
			printf("Enter Key :");
			scanf("%d", &key);
			printf("Input text to decrypt->");
			scanf("%s", &ciphertxt);
			decrypt(ciphertxt, key);
		}
		else
			choice = 0;
	} while (choice != 0);

	return 0;
}